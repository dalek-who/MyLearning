#文件组成
1. makefile
make 编译出可执行文件ucasdb
2. SQLparser.c
语法分析器、读取文件main函数
3. SQLexec.h
执行阶段所需要宏定义结构体、执行部分函数
4. SQLexec.c
create table、 drop table、 insert、
select最普通选择投影函数所在位置
5. SQLjoin.c
select简单连接所在位置
6. SQLgroupby.c
select分组聚集+连接功能所在位置

#运行方式
make后，在可执行文件所在目录，执行./ucasdb接相应文件名，运行完成后，在可执行文件所在目录下db子目录产生表相关.tbl文件
##示例
./ucasdb myexample.sql