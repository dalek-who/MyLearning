cuda+opengl
概述：
cuda能使用gpu编程，访问显存空间，并进行计算操作
opengl有扩展库glew，能创建缓冲区，并使用缓冲区资源绘图
两者结合，即cuda直接操作opengl的缓冲区，来实现opengl+cuda的交互开发。

前者cuda：
CUDA学习笔记一 - 从入门到放弃 - CSDN博客
http://blog.csdn.net/langb2014/article/details/51348425

后者opengl缓冲区：
OpenGL VBO, PBO与FBO介绍
http://blog.csdn.net/ym19860303/article/details/9400609
关于OPENGL缓冲区更具体些
2D
OpenGL像素缓冲区对象PBO
http://blog.csdn.net/dreamcs/article/details/7708018
官方介绍PBO(http://www.songho.ca/opengl/gl_pbo.html)
3D
顶点缓存对象（VBO）
http://www.cnblogs.com/hefee/p/3824300.html
官方介绍VBO(http://www.songho.ca/opengl/gl_vbo.html)

结合：
CUDA与OpenGL交互开发(交互开发的基础设置，具体代码里都有用注释写)
http://blog.csdn.net/ruby97/article/details/8851403
主要是：
需要opengl扩展库glew库(需要在opengl初始化代码最后加上：glewInit())(#include "gl/glew.h"，且其声明的位置尽量放在代码最顶端，否则编译报错。)
cuda和opengl的分别初始化。
opengl申请缓冲区空间。
cuda注册opengl的缓冲区空间。
cuda申请访问，及结束访问（访问时，opengl无法访问该缓冲区空间）
opengl调用缓冲区空间数据绘图。

CUDA+OpenGL混合编程示例(PBO, 使用unpack，glDrawPixels)
http://blog.csdn.net/dcrmg/article/details/54917584
(该例子可能缺少的头文件#include "device_launch_parameters.h" #include <math.h> #include <windows.h>)
(该博客，还有其他PBO，使用glTexImage2D绘图的例子)

cuda与opengl互操作之VBO(3D绘图的，具体我没有看)
http://blog.csdn.net/traceorigin/article/details/9211421

