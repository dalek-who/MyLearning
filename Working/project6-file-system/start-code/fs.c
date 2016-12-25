/*
 * Implementation of a Unix-like file system.
*/
#include "util.h"
#include "common.h"
#include "block.h"
#include "fs.h"

#ifdef FAKE
#include <stdio.h>
#define ERROR_MSG(m) printf m;
#else
#define ERROR_MSG(m)
#endif
//DO
static super_block_t *super_block;
static char super_block_buf[BLOCK_SIZE];
static descriptor_t file_table[MAX_FD_TABLE];
static short current_dir;
static char cname[MAX_FILE_NAME + 1] = ".";
static char fname[MAX_FILE_NAME + 1] = "..";

static void data_read(short index, char *data_buf);
static void data_write(short index, char *data_buf);
static inode_t *inode_read(short index, char *inode_buf);
static void inode_write(short index, char *inode_buf);
static void inode_init(short index, int type);
static short space_alloc(int type);
static void space_free(short index, int type, int number);
static void dir_delete(file_entry_t *file);
static int dir_delete_swap(char *name, int dir_inode);
static int dir_insert(char *name, short dir_inode, short entry_inode);
static short dir_find(char *name, short dir_inode);
static short add_block(inode_t *inode);
static short path_lookup(char *name);
static int fd_alloc(short index, int flags);
static void fd_free(int fd);

static void data_read(short index, char *data_buf)
{
    if(index >= super_block->data_blocks || index < 0)
        return;
    block_read(super_block->data_start + index, data_buf);
}
static void data_write(short index, char *data_buf)
{
    if(index >= super_block->data_blocks || index < 0)
        return;
    block_write(super_block->data_start + index, data_buf);
}
static inode_t *inode_read(short index, char *inode_buf)
{
    if(index >= super_block->inode_blocks || index < 0)
        return NULL;
    inode_t *inodes;
    int i, j;
    i = index / INODE_COUNT;
    j = index % INODE_COUNT;
    block_read(super_block->inode_start + i, inode_buf);
    inodes = (inode_t *)inode_buf;
	return &inodes[j];
}
static void inode_write(short index, char *inode_buf)
{
    if(index >= super_block->inode_blocks || index < 0)
        return;
    int i;
    i = index / INODE_COUNT;
    block_write(super_block->inode_start + i, inode_buf);
}
static void inode_init(short index, int type)
{
    char inode_buf[BLOCK_SIZE];
    inode_t *inode;
    if(index < 0 || index >= super_block->inode_number)
        return;
    inode = inode_read(index, inode_buf);
    inode->size = 0;
    inode->type = type;
    inode->number = 0;
    inode->used_blocks = 0;
    bzero((char *)inode->blocks, sizeof(inode->blocks));
    inode->indirect_block = 0;
    inode->links = 0;
    inode_write(index, inode_buf);
}
static short space_alloc(int type)
{
    char bitmap_buf[BLOCK_SIZE];
    int i, j, index, start, end;
	char flag;
    if(type == INODE_TYPE)
    {
        start = 0;
        end = super_block->inode_number;
    }
    else
    {
        start = super_block->inode_number;
        end = super_block->inode_number + super_block->data_blocks;
    }
    block_read(super_block->bitmap_start + start / BLOCK_BIT, bitmap_buf);
    for(index = start; index < end; index ++)
    {
        if(index % BLOCK_BIT == 0)
            block_read(super_block->bitmap_start + index / BLOCK_BIT, bitmap_buf);
        i = index / 8;
        j = index % 8;
        flag = bitmap_buf[i] << j;
        if(flag >= 0)
        {
            bitmap_buf[i] += 1 << (8 - 1 - j);
            block_write(super_block->bitmap_start + index / BLOCK_BIT, bitmap_buf);
            return index - start;
        }
    }
    return -1;
}
static void space_free(short index, int type, int number)
{
    char bitmap_buf[BLOCK_SIZE];
    int i, j;
	char flag;
    if((index < 0 || index >= super_block->inode_number) && type == INODE_TYPE)
        return;
    if((index < 0 || index >= super_block->data_blocks) && type != INODE_TYPE)
        return;   
    if(type == INODE_TYPE && index == ROOT_DIRECTORY)
        return;
    if(type != INODE_TYPE)
        index += super_block->inode_number;
    block_read(super_block->bitmap_start + index / BLOCK_BIT, bitmap_buf);
    i = index / 8;
    j = index % 8;
    flag = bitmap_buf[i] << j;
    if(flag < 0)
    {
        bitmap_buf[i] += 1 << (8 - 1 - j);
        block_write(super_block->bitmap_start + index / BLOCK_BIT, bitmap_buf);
    }
    else return;
    if(type == FILE_TYPE)
        return;
    else if(type == INODE_TYPE)
    {
        char inode_buf[BLOCK_SIZE];
        inode_t *inode;
        inode = inode_read(index, inode_buf);
        int i;
        for(i = 0, number = inode->number; i < inode->used_blocks && i < DIRECT_BLOCK_NUM; i++, number-= DIR_ENTRY_COUNT)
            space_free(inode->blocks[i], inode->type, number);
        if(inode->used_blocks > DIRECT_BLOCK_NUM)
        {
            char indirect_buf[BLOCK_SIZE];
            short *block;
            block = (short *)indirect_buf;
            data_read(inode->indirect_block, indirect_buf);
            space_free(inode->indirect_block, FILE_TYPE, 0);
            for(i = 0; i < inode->used_blocks - DIRECT_BLOCK_NUM; i++, number-= DIR_ENTRY_COUNT)
                space_free(block[i], inode->type, number);
        }
    }
    else if(type == DIRECTORY)
    {
        char dir_buf[BLOCK_SIZE];
        file_entry_t *file;
        int i;
        data_read(index, dir_buf);
        file = (file_entry_t *)dir_buf;
        for(i = 0; i < number && i < DIR_ENTRY_COUNT; i++)
            dir_delete(&file[i]);
    }
}
static void dir_delete(file_entry_t *file)
{
    char inode_buf[BLOCK_SIZE];
    inode_t *inode;
    inode = inode_read(file->inode, inode_buf);
    inode->links--;
    if(inode->links == 0 && (inode->type == DIRECTORY || inode->number == 0))
        space_free(file->inode, INODE_TYPE, 0);
    else inode_write(file->inode, inode_buf);
}
static int dir_delete_swap(char *name, int dir_inode)
{
    char inode_buf[BLOCK_SIZE];
    inode_t *inode;
    inode = inode_read(dir_inode, inode_buf);
    char dir_buf[BLOCK_SIZE];
    file_entry_t *file;
    file = (file_entry_t *)dir_buf;
    int i;
    short block = -1;
    for(i = 0; i < inode->number && i < DIRECT_BLOCK_NUM * DIR_ENTRY_COUNT; i++)
    {
        if(i % DIR_ENTRY_COUNT == 0)
            data_read(inode->blocks[i / DIR_ENTRY_COUNT], dir_buf);
        if(same_string(name, file[i % DIR_ENTRY_COUNT].name))
        {
            block = inode->blocks[i / DIR_ENTRY_COUNT];
            break;
        }
    }
    char indirect_buf[BLOCK_SIZE];
    short *indirect_block;
    indirect_block = (short *)indirect_buf;
    if(inode->used_blocks > DIRECT_BLOCK_NUM)
    {
        data_read(inode->indirect_block, indirect_buf);
        if(block == -1)//要查找间接block
        {
            for(; i < inode->number; i++)
            {
                if(i % DIR_ENTRY_COUNT == 0)
                    data_read(indirect_block[i / DIR_ENTRY_COUNT - DIRECT_BLOCK_NUM], dir_buf);
                if(same_string(name, file[i % DIR_ENTRY_COUNT].name))
                {
                    block = indirect_block[i / DIR_ENTRY_COUNT - DIRECT_BLOCK_NUM];
                    break;
                }
            }
        }
    }
    if(i == inode->number)
        return -1;
    //与最后一个交换
    char last_buf[BLOCK_SIZE];
    file_entry_t *last_file;
    last_file = (file_entry_t *)last_buf;
    short last_block;
    if(inode->used_blocks < DIRECT_BLOCK_NUM)
        last_block = inode->blocks[inode->used_blocks - 1];
    else if(i >= DIRECT_BLOCK_NUM * DIR_ENTRY_COUNT)
        last_block = indirect_block[inode->used_blocks - 1 - DIRECT_BLOCK_NUM];
    data_read(last_block, last_buf);
    dir_delete(&file[i % DIR_ENTRY_COUNT]);
    file[i % DIR_ENTRY_COUNT].inode = last_file[(inode->number - 1) % DIR_ENTRY_COUNT].inode;
    bcopy((unsigned char *)&last_file[(inode->number - 1) % DIR_ENTRY_COUNT].name, (unsigned char *)&file[i % DIR_ENTRY_COUNT].name, MAX_FILE_NAME + 1);
    data_write(block, dir_buf);
    if((inode->number - 1) % DIR_ENTRY_COUNT == 0)
    {
        space_free(last_block, FILE_TYPE, 0);
        inode->used_blocks -= 1;
        if(inode->used_blocks == DIRECT_BLOCK_NUM)
            space_free(inode->indirect_block, FILE_TYPE, 0);
    }
    inode->number--;
    inode->size -= sizeof(file_entry_t);
    inode_write(dir_inode, inode_buf);
    return 0;
}
static int dir_insert(char *name, short dir_inode, short entry_inode)
{
    char inode_buf[BLOCK_SIZE];
    inode_t *inode;
    inode = inode_read(dir_inode, inode_buf);
    char dir_buf[BLOCK_SIZE];
    file_entry_t *file;
    file = (file_entry_t *)dir_buf;
    short block;
    int index;
    index = inode->number % DIR_ENTRY_COUNT;
    if(index == 0)
    {
        block = add_block(inode);
        if(block == -1)
            return -1;
    }
    else
    {
        if(inode->used_blocks <= DIRECT_BLOCK_NUM)
            block = inode->blocks[inode->used_blocks - 1];
        else
        {
            char indirect_buf[BLOCK_SIZE];
            short *indirect_block;
            indirect_block = (short *)indirect_buf;
            data_read(inode->indirect_block, indirect_buf);
            block = indirect_block[inode->used_blocks - DIRECT_BLOCK_NUM - 1];
        }
        data_read(block, dir_buf);
    }
    file[index].inode = entry_inode;
    bcopy((unsigned char *)name, (unsigned char *)file[index].name, MAX_FILE_NAME + 1);
    data_write(block, dir_buf);

    inode->number++;
    inode->size += sizeof(file_entry_t);
    inode_write(dir_inode, inode_buf);

    inode = inode_read(entry_inode, inode_buf);
    inode->links++;
    inode_write(entry_inode, inode_buf);
    return 0;
}
static short dir_find(char *name, short dir_inode)
{
    char inode_buf[BLOCK_SIZE];
    inode_t *inode;
    inode = inode_read(dir_inode, inode_buf);
    char dir_buf[BLOCK_SIZE];
    file_entry_t *file;
    file = (file_entry_t *)dir_buf;
    int i;
    for(i = 0; i < inode->number && i < DIRECT_BLOCK_NUM * DIR_ENTRY_COUNT; i++)
    {
        if(i % DIR_ENTRY_COUNT == 0)
            data_read(inode->blocks[i / DIR_ENTRY_COUNT], dir_buf);
        if(same_string(name, file[i % DIR_ENTRY_COUNT].name))
            return file[i % DIR_ENTRY_COUNT].inode;
    }
    if(inode->used_blocks > DIRECT_BLOCK_NUM)
    {
        char indirect_buf[BLOCK_SIZE];
        short *indirect_block;
        indirect_block = (short *)indirect_buf;
        data_read(inode->indirect_block, indirect_buf);
        for(; i < inode->number; i++)
        {
            if(i % DIR_ENTRY_COUNT == 0)
                data_read(indirect_block[i / DIR_ENTRY_COUNT - DIRECT_BLOCK_NUM], dir_buf);
            if(same_string(name, file[i % DIR_ENTRY_COUNT].name))
                return file[i % DIR_ENTRY_COUNT].inode;
        }
    }
    return -1;   
}
static short add_block(inode_t *inode)
{
    char data_buf[BLOCK_SIZE];
    short block;
    if(inode->used_blocks == MAX_FILE_BLOCK || inode->used_blocks < 0)
        return -1;
    block = space_alloc(FILE_TYPE);
    if(block == -1)
        return -1;
    if(inode->used_blocks < DIRECT_BLOCK_NUM)
        inode->blocks[inode->used_blocks] = block;
    else
    {
        short *indirect_block;
        indirect_block = (short *)data_buf;
        if(inode->used_blocks == DIRECT_BLOCK_NUM)
            inode->indirect_block = space_alloc(FILE_TYPE);
        else data_read(inode->indirect_block, data_buf);
        if(inode->indirect_block == -1)
        {
            space_free(block, FILE_TYPE, 0);
            return -1;
        }
        indirect_block[inode->used_blocks - DIRECT_BLOCK_NUM] = block;
        data_write(inode->indirect_block, data_buf);
    }
    // bzero_block(data_buf);
    // data_write(block, data_buf);
    inode->used_blocks++;
    return block;
}
static short path_lookup(char *name)
{
    int i, count;
    char pname[MAX_FILE_NAME + 1] = {'\0'};
    short dir;
    int length = strlen(name);
    short aim;
    if(name[0] == '/')
        dir = ROOT_DIRECTORY;
    else dir = current_dir;
    if(name[length] == '/')
        length--;
    for(i = 0; i < MAX_PATH_NAME && i < length; i++)
    {
        count = i;
        pname[0] = '\0';
        while(name[i] != '/' && i < length)
        {
            if(i - count < MAX_FILE_NAME)
                pname[i - count] = name[i];
            i++;
        }
        pname[i - count] = '\0';
        if(strlen(pname) > 0)
        {
            aim = dir_find(pname, dir);
            if(aim == -1)
            {
                if(i == length)
                    return -2;//文件不存在，可能根据情况新建
                else return -1;
            }
            char inode_buf[BLOCK_SIZE];
            inode_t *inode;
            inode = inode_read(aim, inode_buf);
            if(inode->type == FILE_TYPE)
            {
                if(i == length)
                    return aim;
                else return -1;
            }
            else dir = aim;
        }
    }
    return dir;
}
static int fd_alloc(short index, int flags)
{
    int fd;
    for(fd = 0; fd < MAX_FD_TABLE; fd++)
        if(!file_table[fd].is_open)
            break;
    if(fd == MAX_FD_TABLE)
        return -1;
    file_table[fd].is_open = TRUE;
    file_table[fd].cursor = 0;
    file_table[fd].inode = index;
    file_table[fd].mode = flags;

    char inode_buf[BLOCK_SIZE];
    inode_t *inode;
    inode = inode_read(fd, inode_buf);
    inode->number++;
    inode_write(fd, inode_buf);

    return fd;
}
static void fd_free(int fd)
{
    file_table[fd].is_open = FALSE;

    char inode_buf[BLOCK_SIZE];
    inode_t *inode;
    inode = inode_read(file_table[fd].inode, inode_buf);
    inode->number--;
    if(inode->links == 0 && inode->number == 0)
        space_free(file_table[fd].inode, INODE_TYPE, 0);
    else inode_write(file_table[fd].inode, inode_buf);  
}
void fs_init(void)
{
    block_init();
    /* More code HERE */
	//比对super和备份

    block_read(SUPER_BLOCK, super_block_buf);
	super_block = (super_block_t *)super_block_buf;
    if(super_block->magic_num != MAGIC_NUMBER)
        block_read(SUPER_BLOCK_BACKUP, super_block_buf);

    //是否需要格式化
    if(super_block->magic_num != MAGIC_NUMBER)
        fs_mkfs();
	//根目录，初始化文件描述符
    current_dir = ROOT_DIRECTORY;
    bzero((char *)file_table, sizeof(file_table));
}

int fs_mkfs(void) {
    //super block
    bzero_block(super_block_buf);
    super_block->fs_size = FS_SIZE;
    super_block->inode_start = SUPER_BLOCK + 1;
    super_block->inode_number = INODE_BLOCKS * INODE_COUNT;
    super_block->inode_blocks = INODE_BLOCKS;
    super_block->bitmap_start = SUPER_BLOCK + 1 + INODE_BLOCKS;
    super_block->bitmap_blocks = BIT_MAP_BLOCKS;
    super_block->data_start = SUPER_BLOCK + 1 + INODE_BLOCKS + BIT_MAP_BLOCKS;
    super_block->data_blocks = DATA_BLOCKS;
    super_block->magic_num = MAGIC_NUMBER;
    block_write(SUPER_BLOCK, super_block_buf);
    block_write(SUPER_BLOCK_BACKUP, super_block_buf);
    //zero out some blocks
    char buffer[BLOCK_SIZE];
    int i;
    bzero_block(buffer);
    // block_write(BOOT_BLOCK, buffer);
    for(i = 0; i < super_block->bitmap_blocks; i++)
        block_write(super_block->bitmap_start + i, buffer);
    //init inodes
    for(i = 0; i < super_block->inode_blocks; i++)
        block_write(super_block->inode_start + i, buffer);
    //creat root directory
    current_dir = space_alloc(INODE_TYPE);
    inode_init(current_dir, DIRECTORY);
    dir_insert(cname, current_dir, current_dir);
    dir_insert(fname, current_dir, current_dir);
    return 0;
    // return -1;
}
int fs_open(char *fileName, int flags)
{
    short index;
    index = path_lookup(fileName);
    if(index == -1 || (index == -2 && flags == 1))
        return -1;
    else if(index == -2)//文件不存在,且非只读模式,创建文件
    {
        char dir_name[MAX_PATH_NAME + 1];
        char pname[MAX_FILE_NAME + 1];
        short dir;
        int length = strlen(fileName);
        int i, count;
        if(fileName[length - 1] == '/')
            length--;
        for(i = 0; i < MAX_PATH_NAME && i < length; i++)
        {
            count = i;
            pname[0] = '\0';
            while(fileName[i] != '/' && i < length)
            {
                if(i - count < MAX_FILE_NAME)
                    pname[i - count] = fileName[i];
                i++;
            }
        }
        bcopy((unsigned char *)fileName, (unsigned char *)dir_name, count);
        dir = path_lookup(dir_name);
        index = space_alloc(INODE_TYPE);
        if(index == -1)
            return -1;
        inode_init(index, FILE_TYPE);
        dir_insert(pname, dir, index);
    }
    int fd;
    fd = fd_alloc(index, flags);
    return fd;
}

int fs_close(int fd)
{
    if(fd >= 0 && fd < MAX_FD_TABLE)
    {
        if(!file_table[fd].is_open)
            return -1;
        fd_free(fd);
        return 0;
    }
    return -1;
}

int fs_read(int fd, char *buf, int count)
{
    if(count == 0 || buf == NULL)
        return 0;
    if(fd >= 0 && fd < MAX_FD_TABLE)
    {
        if(!file_table[fd].is_open)
            return -1;
        char inode_buf[BLOCK_SIZE];
        inode_t *inode;
        inode = inode_read(file_table[fd].inode, inode_buf);
        if(file_table[fd].cursor >= inode->size)
            return 0;
        count = (count > inode->size - file_table[fd].cursor) ? inode->size - file_table[fd].cursor : count;
        int current_block, current_bytes, read_bytes = 0;
        
        char indirect_buf[BLOCK_SIZE];
        short *indirect_block;
        indirect_block = (short *)indirect_buf;
        if(inode->used_blocks > DIRECT_BLOCK_NUM)
            data_read(inode->indirect_block, indirect_buf);
        char data_buf[BLOCK_SIZE];
        int min;
        while(read_bytes < count)
        {
			current_block = file_table[fd].cursor / BLOCK_SIZE;
			current_bytes = file_table[fd].cursor % BLOCK_SIZE;
            if(current_block >= DIRECT_BLOCK_NUM && current_block < MAX_FILE_BLOCK)
                data_read(indirect_block[current_block - DIRECT_BLOCK_NUM], data_buf);
            else data_read(inode->blocks[current_block], data_buf);
            min = (BLOCK_SIZE - current_bytes > count - read_bytes) ? count - read_bytes : BLOCK_SIZE - current_bytes;
            bcopy((unsigned char *)(data_buf + current_bytes), (unsigned char *)(buf + read_bytes), min);
            read_bytes += min;
            file_table[fd].cursor += min;
        }
        return read_bytes;
    }
    return -1;
}
    
int fs_write(int fd, char *buf, int count)
{
    if(count == 0 || buf == NULL)
        return 0;
    if(fd >= 0 && fd < MAX_FD_TABLE)
    {
        if(!file_table[fd].is_open)
            return -1;
        char inode_buf[BLOCK_SIZE];
        inode_t *inode;
        inode = inode_read(file_table[fd].inode, inode_buf);
        //写入之前
        char data_buf[BLOCK_SIZE];
        short data_block;
        if(inode->used_blocks > DIRECT_BLOCK_NUM)
        {
            data_read(inode->indirect_block, data_buf);
            data_block = ((short *)data_buf)[inode->used_blocks - DIRECT_BLOCK_NUM - 1];
        }
        else data_block = inode->blocks[inode->used_blocks - 1];
        data_read(data_block, data_buf);

        if(file_table[fd].cursor > inode->size)
        {
            short block[MAX_FILE_BLOCK];
            int block_num = (file_table[fd].cursor - 1) / BLOCK_SIZE + 1;
            int i;
			if(block_num > MAX_FILE_BLOCK)
				return -1;
            if(block_num == inode->used_blocks)
            {
                for (i = inode->size % BLOCK_SIZE; i < file_table[fd].cursor; i++)
                    data_buf[i] = 0;
                data_write(data_block, data_buf);
            }
            else
            {
                for (i = inode->size % BLOCK_SIZE; i < BLOCK_SIZE; i++)
                    data_buf[i] = 0;
                data_write(data_block, data_buf);
				bzero_block(data_buf);
                for(i = 0; i < block_num - inode->used_blocks; i++)
				{
                    block[i] = add_block(inode);
					data_write(block[i], data_buf);
				}
                if(block[i] == -1)
                {
                    for(; i >= 0; i--)
                    {
                        if(block[i] != -1)
                        {
                            space_free(block[i], FILE_TYPE, 0);
                            inode->used_blocks--;
                        }
                    }
                    if(DIRECT_BLOCK_NUM >= inode->used_blocks && DIRECT_BLOCK_NUM < block_num)
                        if(block[DIRECT_BLOCK_NUM - inode->used_blocks] != -1)
                            space_free(inode->indirect_block, FILE_TYPE, 0);
                    return -1;
                }
            }
        }
		
        int current_block, current_bytes, write_bytes = 0;

        char indirect_buf[BLOCK_SIZE];
        short *indirect_block;
        indirect_block = (short *)indirect_buf;
        if(inode->used_blocks > DIRECT_BLOCK_NUM)
            data_read(inode->indirect_block, indirect_buf);
        int min;
        while(write_bytes < count)
        {
			current_block = file_table[fd].cursor / BLOCK_SIZE;
			current_bytes = file_table[fd].cursor % BLOCK_SIZE;
			if(current_block >= MAX_FILE_BLOCK || current_block < 0)
				break;
            if(current_block >= inode->used_blocks)
			{
                if(add_block(inode) == -1)
                    break;
				if(current_block == DIRECT_BLOCK_NUM)
					data_read(inode->indirect_block, indirect_buf);
			}
            if(current_block >= DIRECT_BLOCK_NUM)
                data_read(indirect_block[current_block - DIRECT_BLOCK_NUM], data_buf);
            else data_read(inode->blocks[current_block], data_buf);

            min = (BLOCK_SIZE - current_bytes > count - write_bytes) ? count - write_bytes : BLOCK_SIZE - current_bytes;
            bcopy((unsigned char *)(buf + write_bytes), (unsigned char *)(data_buf + current_bytes), min);
		
            if(current_block >= DIRECT_BLOCK_NUM)
                data_write(indirect_block[current_block - DIRECT_BLOCK_NUM], data_buf);
            else data_write(inode->blocks[current_block], data_buf);
            write_bytes += min;
            file_table[fd].cursor += min;
        }
		if(file_table[fd].cursor > inode->size)
			inode->size = file_table[fd].cursor;
        inode_write(file_table[fd].inode, inode_buf);
        return write_bytes;
    }
    return -1;
}

int fs_lseek(int fd, int offset) {
    return -1;
}

int fs_mkdir(char *fileName)
{
    return -1;
}

int fs_rmdir(char *fileName)
{
    return -1;
}

int fs_cd(char *dirName)
{
    return -1;
}

int fs_link(char *old_fileName, char *new_fileName)
{
    return -1;
}

int fs_unlink(char *fileName)
{
    return -1;
}

int fs_stat(char *fileName, fileStat *buf)
{
    short file;
    char inode_buf[BLOCK_SIZE];
    inode_t *inode;
    file = path_lookup(fileName);
    inode = inode_read(file, inode_buf);
    if(inode == NULL)
        return -1;
    buf->inodeNo = file;
    buf->type = inode->type;
    buf->links = inode->links;
    buf->size = inode->size;
    buf->numBlocks = inode->used_blocks;
    return 0;
}
