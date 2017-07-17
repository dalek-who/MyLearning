/*
 * Implementation of a Unix-like file system.
*/
#ifndef FS_INCLUDED
#define FS_INCLUDED

//number of sectors 
#define FS_SIZE 2048
//2048b=256B
void fs_init( void);
int fs_mkfs( void);
int fs_open( char *fileName, int flags);
int fs_close( int fd);
int fs_read( int fd, char *buf, int count);
int fs_write( int fd, char *buf, int count);
int fs_lseek( int fd, int offset);
int fs_mkdir( char *fileName);
int fs_rmdir( char *fileName);
int fs_cd( char *dirName);
int fs_link( char *old_fileName, char *new_fileName);
int fs_unlink( char *fileName);
int fs_stat( char *fileName, fileStat *buf);

#define MAX_FILE_NAME 32
#define MAX_PATH_NAME 256  // This is the maximum supported "full" path len, eg: /foo/bar/test.txt, rather than the maximum individual filename len.
//DO
#define BLOCK_COUNT 8
#define EXTENT_SIZE (FS_SIZE / BLOCK_COUNT)
#define EXTENT_BITE (BLOCK_SIZE * BLOCK_COUNT)

#define BLOCK_BIT (EXTENT_BITE * 8)

#define BOOT_BLOCK 0

#define SUPER_BLOCK 1
#define SUPER_BLOCK_BACKUP (EXTENT_SIZE - 1)
#define MAGIC_NUMBER 0xffffffff
typedef struct {
    int magic_num; // 格式化与否
    int extent_size; // 文件系统的大小
    int inode_start; // Inode开始的地方
    int inode_number; // Inode数量
    int inode_blocks; // Inode所占block数
    int bitmap_start; // Block Allocation Map开始的地方
    int bitmap_blocks; // Block Allocation Map所占block数
    int data_start; // Data Block开始的地方
    int data_blocks; // Data Block所占block数
} super_block_t;
//4*9=36B
#define DIRECT_BLOCK_NUM 8 
#define INODE_TYPE 0
#define INODE_PADDING 2
typedef struct {
    int size; // 所占字节大小
    short type; // 类型，目录 或 文件
    short number; //如果是目录，文件数量；如果是文件，打开次数
    short used_blocks; // 再使用的Block数
    short blocks[DIRECT_BLOCK_NUM]; // 直接指向Block
    short indirect_block; // 间接指向Block
    short links; // link数量
    char padding[INODE_PADDING];
}inode_t;
#define MAX_FILE_BLOCK (DIRECT_BLOCK_NUM + EXTENT_BITE / sizeof(short))
#define MAX_FILE_SIZE (MAX_FILE_BLOCK * EXTENT_BITE)
#define INODE_COUNT (EXTENT_BITE / sizeof(inode_t))
//32B
#define ROOT_DIRECTORY 0
#define FILE_PADDING 29
typedef struct{
    short inode; // 文件对应Inode
    char name[MAX_FILE_NAME + 1]; // 文件名
    char padding[FILE_PADDING];//对齐
} file_entry_t;
//64 
#define DIR_ENTRY_COUNT (EXTENT_BITE / sizeof(file_entry_t))
typedef struct{
    bool_t is_open; // 是否打开
    int cursor; // 当前读/写位置
    short inode; // 文件Inode
    short mode; // 读写模式
} descriptor_t;
#define MAX_FD_TABLE 512
#define READ_ONLY 1
#define WRITE_ONLY 2
#define READ_WRITE 3
//b=(i*n+d-1)/m +1
//i=d/n
//b+i+d=f
//m=BLOCK_BIT
//f=EXTENT_SIZE - 3
//n=INODE_COUNT
//f=b+i+d=d + (d/n) + ((d/n)*n+d-1)/m + 1
//d = 1927 i = 120 b = 1
#define BIT_MAP_BLOCKS ((2 * EXTENT_SIZE - 1) / BLOCK_BIT + 1)
//1
#define INODE_BLOCKS ((EXTENT_SIZE - 3 - BIT_MAP_BLOCKS - 1) / (1 + INODE_COUNT) + 1)
//2
#define DATA_BLOCKS (EXTENT_SIZE - 3 - BIT_MAP_BLOCKS - INODE_BLOCKS)
//250
#endif
