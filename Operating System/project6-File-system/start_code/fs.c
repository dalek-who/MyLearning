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
static super_block_t *super_block;
static char super_block_buf[EXTENT_BITE];
static descriptor_t file_table[MAX_FD_TABLE];
static short current_dir;
static char cname[MAX_FILE_NAME + 1] = ".";
static char fname[MAX_FILE_NAME + 1] = "..";

static void extent_read(short index, char *data_buf);
static void extent_write(short index, char *data_buf);
static void extent_zero(char *data_buf);
static void data_read(short index, char *data_buf);
static void data_write(short index, char *data_buf);
static inode_t *inode_read(short index, char *inode_buf);
static void inode_write(short index, char *inode_buf);
static short inode_init(int type);
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

static void extent_read(short index, char *data_buf)
{
	int i;
	for(i = 0; i < BLOCK_COUNT; i++)
		block_read(index * BLOCK_COUNT + i, data_buf + i * BLOCK_SIZE);
}
static void extent_write(short index, char *data_buf)
{
	int i;
	for(i = 0; i < BLOCK_COUNT; i++)
		block_write(index * BLOCK_COUNT + i, data_buf + i * BLOCK_SIZE);
}
static void extent_zero(char *data_buf)
{
	int i;
	for(i = 0; i < BLOCK_COUNT; i++)
		bzero_block(data_buf + i * BLOCK_SIZE);	
}
static void data_read(short index, char *data_buf)
{
    if(index >= super_block->data_blocks || index < 0)
        return;
    extent_read(super_block->data_start + index, data_buf);
}
static void data_write(short index, char *data_buf)
{
    if(index >= super_block->data_blocks || index < 0)
        return;
    extent_write(super_block->data_start + index, data_buf);
}
static inode_t *inode_read(short index, char *inode_buf)
{
    if(index >= super_block->inode_number || index < 0)
        return NULL;
    inode_t *inodes;
    int i, j;
    i = index / INODE_COUNT;
    j = index % INODE_COUNT;
    extent_read(super_block->inode_start + i, inode_buf);
    inodes = (inode_t *)inode_buf;
    return &inodes[j];
}
static void inode_write(short index, char *inode_buf)
{
    if(index >= super_block->inode_number || index < 0)
        return;
    int i;
    i = index / INODE_COUNT;
    extent_write(super_block->inode_start + i, inode_buf);
}
static short inode_init(int type)
{
    char inode_buf[EXTENT_BITE];
    inode_t *inode;
    short index;
    index = space_alloc(INODE_TYPE);
    if(index == -1)
        return -1;
    inode = inode_read(index, inode_buf);
    inode->size = 0;
    inode->type = type;
    inode->number = 0;
    inode->used_blocks = 0;
    inode->links = 0;
    inode_write(index, inode_buf);
    return index;
}
static short space_alloc(int type)
{
    char bitmap_buf[EXTENT_BITE];
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
    for(index = start; index < end; index++)
    {
        if(index % BLOCK_BIT == 0 || index == start)
            extent_read(super_block->bitmap_start + index / BLOCK_BIT, bitmap_buf);
        i = index / 8;
        j = index % 8;
        flag = bitmap_buf[i] << j;
        if(flag >= 0)
        {
            bitmap_buf[i] += 1 << (8 - 1 - j);
            extent_write(super_block->bitmap_start + index / BLOCK_BIT, bitmap_buf);
            return index - start;
        }
    }
    return -1;
}
static void space_free(short index, int type, int number)
{
    char bitmap_buf[EXTENT_BITE];
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
    extent_read(super_block->bitmap_start + index / BLOCK_BIT, bitmap_buf);
    i = index / 8;
    j = index % 8;
    flag = bitmap_buf[i] << j;
    if(flag < 0)
    {
        bitmap_buf[i] -= 1 << (8 - 1 - j);
        extent_write(super_block->bitmap_start + index / BLOCK_BIT, bitmap_buf);
    }
    else return;
    if(type != INODE_TYPE)
        index -= super_block->inode_number;

    if(type == FILE_TYPE)
        return;
    else if(type == INODE_TYPE)
    {
        char inode_buf[EXTENT_BITE];
        inode_t *inode;
        inode = inode_read(index, inode_buf);
        int i;
        for(i = 0, number = inode->number; i < inode->used_blocks && i < DIRECT_BLOCK_NUM; i++, number-= DIR_ENTRY_COUNT)
            space_free(inode->blocks[i], inode->type, number);
        if(inode->used_blocks > DIRECT_BLOCK_NUM)
        {
            char indirect_buf[EXTENT_BITE];
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
        char dir_buf[EXTENT_BITE];
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
    char inode_buf[EXTENT_BITE];
    if(same_string(file->name, cname))
    	return;
    inode_t *inode;
    inode = inode_read(file->inode, inode_buf);
    inode->links--;
    if(inode->links == 0 && inode->number == 0)
        space_free(file->inode, INODE_TYPE, 0);
    else if(inode->type != DIRECTORY || inode->links != 1)
    	inode_write(file->inode, inode_buf);
}
static int dir_delete_swap(char *name, int dir_inode)
{
    char inode_buf[EXTENT_BITE];
    inode_t *inode;
    inode = inode_read(dir_inode, inode_buf);
    char dir_buf[EXTENT_BITE];
    file_entry_t *file;
    file = (file_entry_t *)dir_buf;
    int i;
    short block = -1;
    if(dir_inode == ROOT_DIRECTORY && (same_string(name, cname) || same_string(name, fname)))
        return -1;
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
    char indirect_buf[EXTENT_BITE];
    short *indirect_block;
    indirect_block = (short *)indirect_buf;
    if(inode->used_blocks > DIRECT_BLOCK_NUM)
    {
        data_read(inode->indirect_block, indirect_buf);
        if(block == -1)//要查找间接block
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
    if(i == inode->number)
        return -1;
    //与最后一个交换
    char last_buf[EXTENT_BITE];
    file_entry_t *last_file;
    last_file = (file_entry_t *)last_buf;
    short last_block;
    if(inode->used_blocks < DIRECT_BLOCK_NUM)
        last_block = inode->blocks[inode->used_blocks - 1];
    else last_block = indirect_block[inode->used_blocks - 1 - DIRECT_BLOCK_NUM];
    data_read(last_block, last_buf);
    dir_delete(&file[i % DIR_ENTRY_COUNT]);

    file[i % DIR_ENTRY_COUNT].inode = last_file[(inode->number - 1) % DIR_ENTRY_COUNT].inode;
    bcopy((unsigned char *)&last_file[(inode->number - 1) % DIR_ENTRY_COUNT].name, (unsigned char *)&file[i % DIR_ENTRY_COUNT].name, MAX_FILE_NAME + 1);
    data_write(block, dir_buf);


    inode_read(dir_inode, inode_buf);
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
    char inode_buf[EXTENT_BITE];
    inode_t *inode;
    inode = inode_read(dir_inode, inode_buf);
    
    if(inode->type != DIRECTORY)
        return -1;
    char dir_buf[EXTENT_BITE];
    file_entry_t *file;
    char indirect_buf[EXTENT_BITE];
    short *indirect_block;
    indirect_block = (short *)indirect_buf;
    
    short block;
    int index;
    index = inode->number % DIR_ENTRY_COUNT;

    if(index == 0)
    {
        block = add_block(inode);
        if(block == -1)
            return -1;
    }
    else if(inode->used_blocks <= DIRECT_BLOCK_NUM)
        block = inode->blocks[inode->used_blocks - 1];
    else
    {
        data_read(inode->indirect_block, indirect_buf);
        block = indirect_block[inode->used_blocks - DIRECT_BLOCK_NUM - 1];
    }
    data_read(block, dir_buf);
    file = (file_entry_t *)dir_buf;
    file[index].inode = entry_inode;
    bcopy((unsigned char *)name, (unsigned char *)file[index].name, strlen(name) + 1);
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
    char inode_buf[EXTENT_BITE];
    inode_t *inode;
    inode = inode_read(dir_inode, inode_buf);
    if(inode->type != DIRECTORY)
    	return -1;
    char dir_buf[EXTENT_BITE];
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
        char indirect_buf[EXTENT_BITE];
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
    char data_buf[EXTENT_BITE];
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
    // extent_zero(data_buf);
    // data_write(block, data_buf);
    inode->used_blocks++;
    return block;
}
static short path_lookup(char *name)
{
    if(name == NULL || name[0] == '\0')
        return -1;
    int i, count, start = 0;
    char pname[MAX_FILE_NAME + 1];
    short dir;
    int length = strlen(name);
    short aim;
    if(name[0] == '/')
    {
    	start = 1;
        dir = ROOT_DIRECTORY;
    }
    else dir = current_dir;
    if(name[length - 1] == '/')
        length--;
    for(i = start; i < MAX_PATH_NAME && i < length; i++)
    {
        count = i;
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
            char inode_buf[EXTENT_BITE];
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
        else return -1;
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
    return fd;
}
static void fd_free(int fd)
{
    file_table[fd].is_open = FALSE;
    char inode_buf[EXTENT_BITE];
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

    extent_read(SUPER_BLOCK, super_block_buf);
    super_block = (super_block_t *)super_block_buf;
    if(super_block->magic_num != MAGIC_NUMBER)
        extent_read(SUPER_BLOCK_BACKUP, super_block_buf);

    //是否需要格式化
    if(super_block->magic_num != MAGIC_NUMBER)
        fs_mkfs();
    else extent_write(SUPER_BLOCK, super_block_buf);
    //根目录，初始化文件描述符
    current_dir = ROOT_DIRECTORY;
    bzero((char *)file_table, sizeof(file_table));
}

int fs_mkfs(void)
{
    //super block
    extent_zero(super_block_buf);
    super_block->extent_size = EXTENT_SIZE;
    super_block->inode_start = SUPER_BLOCK + 1;
    super_block->inode_number = INODE_BLOCKS * INODE_COUNT;
    super_block->inode_blocks = INODE_BLOCKS;
    super_block->bitmap_start = SUPER_BLOCK + 1 + INODE_BLOCKS;
    super_block->bitmap_blocks = BIT_MAP_BLOCKS;
    super_block->data_start = SUPER_BLOCK + 1 + INODE_BLOCKS + BIT_MAP_BLOCKS;
    super_block->data_blocks = DATA_BLOCKS;
    super_block->magic_num = MAGIC_NUMBER;
    extent_write(SUPER_BLOCK, super_block_buf);
    extent_write(SUPER_BLOCK_BACKUP, super_block_buf);
    //zero out some blocks
    char buffer[EXTENT_BITE];
    int i;
    extent_zero(buffer);
    for(i = 0; i < super_block->bitmap_blocks; i++)
        extent_write(super_block->bitmap_start + i, buffer);
    //init inodes
    for(i = 0; i < super_block->inode_blocks; i++)
        extent_write(super_block->inode_start + i, buffer);
    //creat root directory
    current_dir = inode_init(DIRECTORY);
    dir_insert(cname, current_dir, current_dir);
    dir_insert(fname, current_dir, current_dir);
    bzero((char *)file_table, sizeof(file_table));
    return 0;
    // return -1;
}
int fs_open(char *fileName, int flags)
{
    short index = -2;
    index = path_lookup(fileName);
    if(index == -1 || (index == -2 && flags == READ_ONLY))
        return -1;
    else if(index == -2)//文件不存在,且非只读模式,创建文件
    {
        char dir_name[MAX_PATH_NAME + 1];
        char pname[MAX_FILE_NAME + 1];
        short dir;
        int length = strlen(fileName);
        int i, count, start = 0;
        if(fileName[length - 1] == '/')
            length--;
        if(fileName[0] == '/')
        	start = 1;
        for(i = start; i < MAX_PATH_NAME && i < length; i++)
        {
            count = i;
            while(fileName[i] != '/' && i < length)
            {
                if(i - count < MAX_FILE_NAME)
                    pname[i - count] = fileName[i];
                i++;
            }
	    	pname[i] = '\0';
        }
        if(count == start)
            dir = current_dir;
        else 
        {
            bcopy((unsigned char *)fileName, (unsigned char *)dir_name, count);
            dir = path_lookup(dir_name);
        }
        index = inode_init(FILE_TYPE);
        if(index == -1)
            return -1;
        dir_insert(pname, dir, index);
    }

    char inode_buf[EXTENT_BITE];
    inode_t *inode;
    inode = inode_read(index, inode_buf);
    if(inode->type == DIRECTORY)
    	return -1;
    int fd;
    fd = fd_alloc(index, flags);
    if(fd != -1)
    {
    	inode->number++;
    	inode_write(index, inode_buf);
    }
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
        if(file_table[fd].mode == WRITE_ONLY)
        	return -1;
        char inode_buf[EXTENT_BITE];
        inode_t *inode;
        inode = inode_read(file_table[fd].inode, inode_buf);
        if(file_table[fd].cursor >= inode->size)
            return 0;
        count = (count > inode->size - file_table[fd].cursor) ? inode->size - file_table[fd].cursor : count;
        int current_block, current_bytes, read_bytes = 0;
        
        char indirect_buf[EXTENT_BITE];
        short *indirect_block;
        indirect_block = (short *)indirect_buf;
        if(inode->used_blocks > DIRECT_BLOCK_NUM)
            data_read(inode->indirect_block, indirect_buf);
        char data_buf[EXTENT_BITE];
        int min;
        while(read_bytes < count)
        {
            current_block = file_table[fd].cursor / EXTENT_BITE;
            if(current_block >= inode->used_blocks)
            	break;
            current_bytes = file_table[fd].cursor % EXTENT_BITE;
            if(current_block >= DIRECT_BLOCK_NUM && current_block < MAX_FILE_BLOCK)
                data_read(indirect_block[current_block - DIRECT_BLOCK_NUM], data_buf);
            else data_read(inode->blocks[current_block], data_buf);
            min = (EXTENT_BITE - current_bytes > count - read_bytes) ? count - read_bytes : EXTENT_BITE - current_bytes;
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
            return 0;
        if(file_table[fd].mode == READ_ONLY)
        	return -1;
        char inode_buf[EXTENT_BITE];
        inode_t *inode;
        inode = inode_read(file_table[fd].inode, inode_buf);
        //写入之前
        char data_buf[EXTENT_BITE];
        short data_block;
        if(inode->used_blocks != 0)
        {
	        if(inode->used_blocks > DIRECT_BLOCK_NUM)
	        {
	            data_read(inode->indirect_block, data_buf);
	            data_block = ((short *)data_buf)[inode->used_blocks - DIRECT_BLOCK_NUM - 1];
	        }
	        else data_block = inode->blocks[inode->used_blocks - 1];
	        data_read(data_block, data_buf);
	    }
        
        if(file_table[fd].cursor > inode->size)
        {
            short block[MAX_FILE_BLOCK];
            int block_num = (file_table[fd].cursor - 1) / EXTENT_BITE + 1;
            int i;
            if(block_num > MAX_FILE_BLOCK)
                return 0;
            if(block_num == inode->used_blocks)
            {
                for (i = inode->size % EXTENT_BITE; i < file_table[fd].cursor; i++)
                    data_buf[i] = 0;
                data_write(data_block, data_buf);
            }
            else
            {
            	if(inode->used_blocks != 0)
            	{
	                for(i = inode->size % EXTENT_BITE; i < EXTENT_BITE; i++)
	                    data_buf[i] = 0;
	                data_write(data_block, data_buf);
	            }
                extent_zero(data_buf);
                for(i = 0; i < block_num - inode->used_blocks; i++)
                {
                    block[i] = add_block(inode);
                    if(block[i] == -1)
                    {
                    	for(i--; i >= 0; i--)
	                    {
                            space_free(block[i], FILE_TYPE, 0);
                            inode->used_blocks--;
                            if(inode->used_blocks == DIRECT_BLOCK_NUM)
                            	space_free(inode->indirect_block, FILE_TYPE, 0);
                        }
	                    return 0;
                    }
                    data_write(block[i], data_buf);
                }
            }
        }
        
        int current_block, current_bytes, write_bytes = 0;
        char indirect_buf[EXTENT_BITE];
        short *indirect_block;
        indirect_block = (short *)indirect_buf;
        if(inode->used_blocks > DIRECT_BLOCK_NUM)
            data_read(inode->indirect_block, indirect_buf);
        int min;
		short now_block;
        while(write_bytes < count)
        {
            current_block = file_table[fd].cursor / EXTENT_BITE;
            current_bytes = file_table[fd].cursor % EXTENT_BITE;
            if(current_block >= MAX_FILE_BLOCK || current_block < 0)
                break;
            if(current_block == inode->used_blocks)
            {
                now_block = add_block(inode);
				if(now_block == -1)
                    break;
            }
            else
		    {
				if(current_block >= DIRECT_BLOCK_NUM)
		                    now_block = indirect_block[current_block - DIRECT_BLOCK_NUM];
				else now_block = inode->blocks[current_block];
		    }
	    	data_read(now_block, data_buf);
            min = (EXTENT_BITE - current_bytes > count - write_bytes) ? count - write_bytes : EXTENT_BITE - current_bytes;
            bcopy((unsigned char *)(buf + write_bytes), (unsigned char *)(data_buf + current_bytes), min);

            data_write(now_block, data_buf);
            write_bytes += min;
            file_table[fd].cursor += min;
        }
        if(file_table[fd].cursor > inode->size)
            inode->size = file_table[fd].cursor;
        inode_write(file_table[fd].inode, inode_buf);
        return write_bytes;
    }
    return 0;
}

int fs_lseek(int fd, int offset) 
{
    if(fd < 0 || fd >= MAX_FD_TABLE)
        return -1;
    if(offset < 0 || !file_table[fd].is_open)
        return -1;
    file_table[fd].cursor = offset;
    return offset;
}

int fs_mkdir(char *fileName)
{
    short file;
    file = path_lookup(fileName);
    if(file >= 0)
        return -1;
    file = inode_init(DIRECTORY);
    if(file == -1)
        return -1;
    if(dir_insert(cname, file, file) == -1)
    {
        space_free(file, INODE_TYPE, 0);
        return -1;
    }
    char dir_name[MAX_PATH_NAME + 1];
    char pname[MAX_FILE_NAME + 1];
    short dir;
    int length = strlen(fileName);
    int i, count, start = 0;
    if(fileName[length - 1] == '/')
        length--;
    if(fileName[0] == '/')
    	start = 1;
    for(i = start; i < MAX_PATH_NAME && i < length; i++)
    {
        count = i;
        while(fileName[i] != '/' && i < length)
        {
            if(i - count < MAX_FILE_NAME)
                pname[i - count] = fileName[i];
            i++;
        }
        pname[i - count] = '\0';
    }
    if(count == start)
    	dir = current_dir;
	else
	{
		bcopy((unsigned char *)fileName, (unsigned char *)dir_name, count);
		dir = path_lookup(dir_name);
	}
    if(dir_insert(pname, dir, file) == -1)
    {
        space_free(file, INODE_TYPE, 0);
        return -1;
    }
    dir_insert(fname, file, dir);
    
    return 0;
}

int fs_rmdir(char *fileName)
{
    short file;
    file = path_lookup(fileName);
    if(file < 0)
        return -1;
    char inode_buf[EXTENT_BITE];
    inode_t *inode;
    inode = inode_read(file, inode_buf);
    if(inode->type != DIRECTORY)
        return -1;
    
    char dir_name[MAX_PATH_NAME + 1];
    char pname[MAX_FILE_NAME + 1];
    short dir;
    int length = strlen(fileName);
    int i, count, start = 0;
    if(fileName[length - 1] == '/')
        length--;
    if(fileName[0] == '/')
    	start = 1;
    for(i = start; i < MAX_PATH_NAME && i < length; i++)
    {
        count = i;
        while(fileName[i] != '/' && i < length)
        {
            if(i - count < MAX_FILE_NAME)
                pname[i - count] = fileName[i];
            i++;
        }
        pname[i - count] = '\0';
    }
    if(count == start)
    	dir = current_dir;
	else
	{
		bcopy((unsigned char *)fileName, (unsigned char *)dir_name, count);
		dir = path_lookup(dir_name);
	}

    dir_delete_swap(pname, dir);
    space_free(file, INODE_TYPE, 0);
    return 0;
}

int fs_cd(char *dirName)
{
    if(same_string(dirName, cname))
        return 0;
    short dir;
    dir = path_lookup(dirName);
    if(dir < 0)
        return -1;
    
    char inode_buf[EXTENT_BITE];
    inode_t *inode;
    inode = inode_read(dir, inode_buf);
    if(inode->type != DIRECTORY)
        return -1;
    current_dir = dir;
    return 0;
}

int fs_link(char *old_fileName, char *new_fileName)
{
    short file;
    if(new_fileName == NULL)
        return -1;
    
    file = path_lookup(old_fileName);
    if(file < 0)
        return -1;
    char inode_buf[EXTENT_BITE];
    inode_t *inode;
    inode = inode_read(file, inode_buf);
    if(inode->type == DIRECTORY)
    	return -1;

    if(path_lookup(new_fileName) >= 0)
        return -1;

	char dir_name[MAX_PATH_NAME + 1];
    char pname[MAX_FILE_NAME + 1];
    short dir;
    int length = strlen(new_fileName);
    int i, count, start = 0;
    if(new_fileName[length - 1] == '/')
        length--;
    if(new_fileName[0] == '/')
    	start = 1;
    for(i = start; i < MAX_PATH_NAME && i < length; i++)
    {
        count = i;
        while(new_fileName[i] != '/' && i < length)
        {
            if(i - count < MAX_FILE_NAME)
                pname[i - count] = new_fileName[i];
            i++;
        }
        pname[i - count] = '\0';
    }
    if(count == start)
    	dir = current_dir;
	else
	{
		bcopy((unsigned char *)new_fileName, (unsigned char *)dir_name, count);
		dir = path_lookup(dir_name);
	}

    if(dir_insert(pname, current_dir, file) == -1)
        return -1;
    return 0;
}

int fs_unlink(char *fileName)
{
    short file;
    file = path_lookup(fileName);
    if(file < 0)
        return -1;
    char inode_buf[EXTENT_BITE];
    inode_t *inode;
    inode = inode_read(file, inode_buf);
    if(inode->type == DIRECTORY)
    	return -1;

    char dir_name[MAX_PATH_NAME + 1];
    char pname[MAX_FILE_NAME + 1];
    short dir;
    int length = strlen(fileName);
    int i, count, start = 0;
    if(fileName[length - 1] == '/')
        length--;
    if(fileName[0] == '/')
    	start = 1;
    for(i = start; i < MAX_PATH_NAME && i < length; i++)
    {
        count = i;
        while(fileName[i] != '/' && i < length)
        {
            if(i - count < MAX_FILE_NAME)
                pname[i - count] = fileName[i];
            i++;
        }
        pname[i - count] = '\0';
    }
    if(count == start)
    	dir = current_dir;
	else
	{
		bcopy((unsigned char *)fileName, (unsigned char *)dir_name, count);
		dir = path_lookup(dir_name);
	}

    dir_delete_swap(pname, dir); 
    return 0;
}

int fs_stat(char *fileName, fileStat *buf)
{
    short file;
    char inode_buf[EXTENT_BITE];
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

int fs_ls(short index, char *name)
{
	char inode_buf[EXTENT_BITE];
	char data_buf[EXTENT_BITE];
	inode_t *inode;
	inode = inode_read(current_dir, inode_buf);
	if(index >= inode->number || index < 0)
		return -1;
	short block;
	block = index / DIR_ENTRY_COUNT;
	if(block < DIRECT_BLOCK_NUM)
		block = inode->blocks[block];
	else
	{
		data_read(inode->indirect_block, data_buf);
		block = ((short *)data_buf)[block - DIRECT_BLOCK_NUM];
	}
	data_read(block, data_buf);
	file_entry_t *file;
	file = (file_entry_t *)data_buf;
	bcopy((unsigned char *)&file[index % DIR_ENTRY_COUNT].name, (unsigned char *)name, MAX_FILE_NAME + 1);
	return file[index % DIR_ENTRY_COUNT].inode;
}