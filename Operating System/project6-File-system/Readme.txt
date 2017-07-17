测试结果是在result.txt中，目前看结果都是没有发生错误。
测试内容是test.py的原本内容+自己写了一个测试rmdir的。

代码部分，除了fs.c,fs.h，还修改了shell.c。
比如ls部分，不过ls比较简单粗暴，只输出了inode和filename，其他一概没有管。
修改了create部分，让他每次写都是512字节的写，加快速度，不然测一个这个就要很久很久。
之外，由于link数目很多，大于char可以表示部分，还修改了common.h中关于fileStat结构的link类型，由char改为short，不然超过127之后就会显示不正常，显示负数。
其余应该都没有改过。

由于在256个文件系统逻辑块下，只有256个INODE，不便于测试，所以测试的时候，fs.h中
#define EXTENT_SIZE 1024//(FS_SIZE / BLOCK_COUNT)
源代码为注释掉部分，为便于测试改为1024，使之更大。
所以disk也是4MB大小，shell测试里面的check_fs_size被注释掉，因为大于1MB。

大部分解说在报告里，主要定义都是宏定义，可修改。