#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "gl\glew.h"
#include <gl\GL.h>
#include <gl\glu.h>
#include "gl\glut.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <cuda_runtime.h>
#include <cuda.h>
#include "device_launch_parameters.h"
#include <cuda_gl_interop.h>

#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"

#define GET_PROC_ADDRESS(str) wglGetProcAddress(str)
#define DIM 128

PFNGLBINDBUFFERARBPROC    glBindBuffer = NULL;
PFNGLDELETEBUFFERSARBPROC glDeleteBuffers = NULL;
PFNGLGENBUFFERSARBPROC    glGenBuffers = NULL;
PFNGLBUFFERDATAARBPROC    glBufferData = NULL;

GLuint bufferObj;
cudaGraphicsResource *resource;
GLuint bufferObj1;
cudaGraphicsResource *resource1;

const GLfloat lightPosition[] = {10.0,10.0,10.0,0.0};
const GLfloat whiteLight[] = {0.8,0.8,0.8,1.0};
GLfloat matSpecular [] = {0.3,0.3,0.3,1.0};
GLfloat matShininess [] = {20.0};
//GLfloat matEmission [] = {0.3,0.3,0.3,1.0};
GLfloat matEmission [] = {1,1,1,1.0};
GLfloat matEmission2 [] = {0,0,0,0.0};
GLfloat spin = 180;
GLfloat projMatrix[16] = {  1.1160 ,   1.9906   , 0.0373 ,   0.1244,
	1.3925  , -1.4027  ,  0.1231  ,  0.4105,
	-0.8277 ,  0.3304 ,   0.2710  ,  0.9033,
	0.3545 ,  -0.2735 ,   1.3939 ,   4.6464  };
GLfloat projMatrix1[16] = {  1.11599 ,   1.99059   , 0.0373221 ,   0.124407,
	1.39251  , -1.40265  ,  0.123144  ,  0.41048,
	-0.827706 ,  0.330419 ,   0.271003  ,  0.903343,
	0.354539 ,  -0.273485 ,   1.39393 ,   4.64644  };
GLfloat headTran[16] = { 2.04317, 2.88461 ,-0.0186038 ,0, 
	-3.00478, 2.0353 ,-0.293618,0 ,
	0.232629 ,-0.180116, -3.62916 ,0,
	1.79757 ,-1.13934 ,-0.917011, 1 };
GLfloat mProj[16];

bool flag = false;
void grab()   
{  
	int width = 320;
	int heith = 256;
	char *mpixels = new  char[width * heith * 3];
	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, width, heith, GL_RGB, GL_BYTE, mpixels);
	//glReadBuffer(GL_BACK);
	for(int i = 0;i < (int)width*heith*3;i += 3)  
	{     
		mpixels[i] ^= mpixels[i+2] ^= mpixels[i] ^= mpixels[i+2];
	}  
	cv::Mat dispImg;
	dispImg.create(cv::Size(width,heith), CV_8UC3 );
	for(int y = 0 ;y < heith;y++)  
	{  
		for(int x = 0 ;x < width;x++)  
		{  
			dispImg.at<cv::Vec3b>(y,x)[0] =mpixels[(y*width+x) * 3 + 0];
			dispImg.at<cv::Vec3b>(y,x)[1] =mpixels[(y*width+x) * 3 + 1];
			dispImg.at<cv::Vec3b>(y,x)[2] =mpixels[(y*width+x) * 3 + 2];
		}  

	}  
	cv::Mat dst;
	//32 BIT - 32 BIT
	cvtColor(dispImg, dst, CV_RGB2GRAY);
	width = dst.cols;
	int heigh = dst.rows;
	for ( int x=0;x<width/2 ;x++)
	{
		for ( int y=0;y<heigh/2;y++)
		{
			dst.at<uchar>(y,x) = 0;
			continue;
		}
	}
	cv::imwrite( "test.jpg", dst );
}
void init()
{
	// Add lighting here
	// Add lighting here
	GLfloat ambient[]  = {(float)0.4, (float)0.4, (float)0.4, (float)1.0};
	GLfloat diffuse[]  = {(float)1.0, (float)1.0, (float)1.0, (float)1.0};
	GLfloat specular[] = {(float)1.0, (float)1.0, (float)1.0, (float)1.0};
	GLfloat lightpos[] = {0.0f,0.0f,1.0f,0.0f};
	// Init all the lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHTING,GL_POSITION,lightpos);

	//glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	// Add basic camera here

	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClearDepth(1.0);
	//glClearColor(1.0f,1.0f,1.0f,1.0f);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	//glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClearStencil(0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);	
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glShadeModel(GL_SMOOTH);
}
void display()  
{
	if(flag)
	{
		glDrawPixels(DIM, DIM, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glutSwapBuffers();
	}
	else
	{
		GLint    viewport[4];
		GLdouble modelview[16];
		GLdouble projection[16];
		//GLdouble  winX, winY, winZ;
		GLdouble posX, posY, posZ;
		GLdouble posX1, posY1, posZ1;

		posX = -0.4054;	posY = 0.2393;	posZ = -2.5986;
		posX = -0.0;	posY = -0;		posZ =  -20.0;
		posX = -0.2421;	posY = 0.4427;	posZ = 0.2279;
		posX1 = 0.3052;	posY1 = 0.4601;	posZ1 = 0.2360;
	
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMultMatrixf(projMatrix);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glMultMatrixf(headTran);
		glPushMatrix();
			glTranslatef(posX, posY, posZ);
			//std::cout<<spin<<std::endl;
				glRotatef(spin,0.0,1.0,0.0);
				glMaterialfv(GL_FRONT,GL_SPECULAR, matSpecular);
				glMaterialfv(GL_FRONT,GL_SHININESS, matShininess);
				glMaterialfv(GL_FRONT,GL_EMISSION, matEmission);
				glutSolidSphere(0.1507,50,50);
				glPushMatrix();
				glTranslatef(0.1507*0.8, 0, 0);
				glMaterialfv(GL_FRONT,GL_EMISSION, matEmission2);
				//glColor3f(0.0f, 0.0f, 0.0f);
				glutSolidSphere(0.4*0.1507,50,50);
				glPopMatrix();
			glPopMatrix();
		glPushMatrix();
		glutSwapBuffers();
		glFlush();
		//flag = true;
	}
}
__global__ void cudaGLKernel(uchar4 *ptr, uchar4 *ptr1)
{
    int x = threadIdx.x + blockIdx.x * blockDim.x;
    int y = threadIdx.y + blockIdx.y * blockDim.y;
    int offset = x + y * blockDim.x * gridDim.x;
      
    /*float fx = x / (float)DIM - 0.5f;
    float fy = y / (float)DIM - 0.5f;*/  
      
    ptr[offset].x = ptr1[offset].x;
    ptr[offset].y = ptr1[offset].y;
    ptr[offset].z = ptr1[offset].z;
    ptr[offset].w = ptr1[offset].w;
}
__global__ void cudaGray(uchar4 *ptr, uchar4 *ptr1, float *result, float *result1)
{
    int x = threadIdx.x + blockIdx.x * blockDim.x;
    int y = threadIdx.y + blockIdx.y * blockDim.y;
    int offset = x + y * blockDim.x * gridDim.x;

    /*float fx = x / (float)DIM - 0.5f;
    float fy = y / (float)DIM - 0.5f;*/  

	result[offset] = ptr[offset].x * 0.3 +ptr[offset].y * 0.3 + ptr[offset].z * 0.4;
	result1[offset] = ptr1[offset].x * 0.3 +ptr1[offset].y * 0.3 + ptr1[offset].z * 0.4;
}
__global__ void cudaCaculate(float *result, float *result1, double *answer)
{
    /*float fx = x / (float)DIM - 0.5f;
    float fy = y / (float)DIM - 0.5f;*/
	int length = DIM * DIM;
	int z = 0;
	answer[0]=0;
	answer[1]=0;
	answer[2]=0;
	answer[3]=0;
	answer[4]=0;
	int offset = 0;
	for (int x = 0; x < DIM; x++)
	{
		for (int y = 0; y < DIM; y++)
		{
			answer[0] += result[offset];//SumX
			answer[1] += result1[offset];//SumY
			answer[2] += (result[offset]*result[offset]);//SumXX
			answer[3] += (result[offset]*result1[offset]);//SumXY
			answer[4] += (result1[offset]*result1[offset]);//SumYY
			offset++;
		}
	}
	answer[5] = (DIM*DIM*answer[3] - answer[0]*answer[1]) / (sqrt(DIM*DIM*answer[2]-answer[0]*answer[0])*sqrt(DIM*DIM*answer[4]-answer[1]*answer[1]));
}
void drawFunc(void)
{
	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, DIM, DIM, GL_BGRA, GL_UNSIGNED_BYTE, 0);
	//CUDA映射共享资源，并获取相对于显卡而言的设备指针
    uchar4* devPtr;
    size_t size;
    cudaGraphicsMapResources(1, &resource, NULL);
    cudaGraphicsResourceGetMappedPointer((void**)&devPtr, &size, resource);
	
	uchar4* devPtr1;
    size_t size1;
    cudaGraphicsMapResources(1, &resource1, NULL);
    cudaGraphicsResourceGetMappedPointer((void**)&devPtr1, &size1, resource1);

	//执行CUDA核函数
    
	if(flag == false)
	{
		dim3 grids(DIM / 16, DIM / 16);
		dim3 threads(16, 16);
		cudaGLKernel<<<grids, threads>>>(devPtr, devPtr1);
		printf("\nsave picture to devPtr");
	}
	else
	{
		cudaError_t cudaStatus;
		printf("\ncalculating");
		float *result, *result1;
		double *answer, *cpuresult;
		dim3 grids(DIM / 16, DIM / 16);
		dim3 threads(16, 16);
		size_t nBytes = DIM * DIM * sizeof(float);
		size_t nBytes1 = 6 * sizeof(double);
		cudaStatus = cudaMalloc((float **)&result, nBytes);
		if (cudaStatus != cudaSuccess) {  
			fprintf(stderr, "cudaMalloc failed!");  
			return;  
		}
		cudaStatus = cudaMalloc((float **)&result1, nBytes);
		if (cudaStatus != cudaSuccess) {  
			fprintf(stderr, "cudaMalloc failed!");
			cudaFree(result);
			return;  
		}
		cudaStatus = cudaMalloc((double **)&answer, nBytes1);
		if (cudaStatus != cudaSuccess) {  
			fprintf(stderr, "cudaMalloc failed!");
			cudaFree(result);
			cudaFree(result1);
			return;  
		}
		cpuresult = (double *)malloc(nBytes1);
		//处理计算一下灰度，并移动数据
		cudaGray<<<grids, threads>>>(devPtr, devPtr1, result, result1);
		//等待完成
		cudaStatus = cudaThreadSynchronize();
		if (cudaStatus != cudaSuccess) {  
			printf("cudaThreadSynchronize returned error code %d after launching addKernel!\n");  
			cudaFree(result);
			cudaFree(result1);
			cudaFree(answer);
			free(cpuresult);
			return;
		}
		//单线程计算相关系数
		cudaCaculate<<<1, 1>>>(result, result1, answer);
		//等待完成
		cudaStatus = cudaThreadSynchronize();
		if (cudaStatus != cudaSuccess) {  
			printf("cudaThreadSynchronize returned error code %d after launching addKernel!\n");  
			cudaFree(result);
			cudaFree(result1);
			cudaFree(answer);
			free(cpuresult);
			return;
		}
		//把结果从显存复制到内存
		cudaStatus = cudaMemcpy(cpuresult, answer, nBytes1, cudaMemcpyDeviceToHost);
		if (cudaStatus != cudaSuccess) {  
			printf("cudaMemcpy failed!");
			cudaFree(result);
			cudaFree(result1);
			cudaFree(answer);
			free(cpuresult);
			return;
		}
		printf("\nSumX:%lg \nSumY:%lg \nSumXX:%lg \n%SumXY:lg \n%SumYY:lg \nResult:%lg", cpuresult[0], cpuresult[1], cpuresult[2], cpuresult[3], cpuresult[4], cpuresult[5]);
		cudaFree(result);
		cudaFree(result1);
		cudaFree(answer);
		free(cpuresult);
		flag = false;
	}
	//解除CUDA对共享缓冲区的映射
	//如果不解除映射，OpenGL将没有权限访问共享数据区
    cudaGraphicsUnmapResources(1, &resource, NULL);
	cudaGraphicsUnmapResources(1, &resource1, NULL);
}
void reshape(int w,int h)  
{
	glViewport(0.0,0.0,(GLsizei) w,(GLsizei) h);
}
void keyboardFunc(unsigned char key,int x,int y)
{
	switch(key)  
	{
	case 'a':  
		spin +=10;
		flag = false;
		break;
	case 'd':  
		spin -=10;
		flag = false;
		break;
	case 's':
		drawFunc();
		break;
	case 'f':
		clock_t start, finish, end;
		start = clock();
		for(int i = 0; i < 900; i++)
		{
			drawFunc();
		}
		finish = clock();
		for(int i = 0; i < 900; i++)
		{
			grab();
		}
		end = clock();
		printf("\n%d\n%d", finish-start, end-finish);
		break;
	case 'q':
		flag = true;
		drawFunc();
		break;
	case 'g':
		flag = true;
		break;
	}
	//if(spin<360)  
	//	spin +=360;
	//else if(spin>=360)  
	//	spin -=360;
	glutPostRedisplay();
}
void mouseFunc(int button,int state,int x,int y)
{  
	if(state == GLUT_DOWN){  
		/*switch (button)  
		{  
		case GLUT_LEFT_BUTTON:  
			matEmission[0]+=1.0;
			if(matEmission[0]>1.0)  
				matEmission[0]-=1.1;
			break;
		case GLUT_MIDDLE_BUTTON:  
			matEmission[1]+=1.0;
			if(matEmission[1]>1.0)  
				matEmission[1]-=1.1;
			break;
		case GLUT_RIGHT_BUTTON:  
			matEmission[2]+=1.0;
			if(matEmission[2]>1.0)  
				matEmission[2]-=1.1;
			break;
		}  */
		glutPostRedisplay();
	}
}
int main(int argc, char* argv[])
{
    //选择在计算功能集的版本号为1.0的GPU设备上运行
	//CUDA5.5及以后的版本无需设置
    //cudaDeviceProp prop;
    //int dev;
    //memset(&prop, 0, sizeof(cudaDeviceProp));
    //prop.major = 1;
    //prop.minor = 0;
    //cudaChooseDevice(&dev, &prop);
	//cudaError_t cudaStatus;
    //cudaStatus = cudaGLSetGLDevice(dev);
    //if (cudaStatus != cudaSuccess) {  
    //    fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");  
    //    return 0;
    //}

    //OpenGL环境初始化    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(DIM, DIM);
    glutCreateWindow("CUDA + OpenGL");
      
    glBindBuffer = (PFNGLBINDBUFFERARBPROC)GET_PROC_ADDRESS("glBindBuffer");
    glDeleteBuffers = (PFNGLDELETEBUFFERSARBPROC)GET_PROC_ADDRESS("glDeleteBuffers");
    glGenBuffers = (PFNGLGENBUFFERSARBPROC)GET_PROC_ADDRESS("glGenBuffers");
    glBufferData = (PFNGLBUFFERDATAARBPROC)GET_PROC_ADDRESS("glBufferData");

	//生成一个缓冲区句柄, 将句柄绑定到像素缓冲区(即缓冲区存放的数据类型为：PBO)
	//申请显卡内存空间并设置相关属性以及初始值
	//GL_ARRAY_BUFFER 3D绘图
	//GL_PIXEL_UNPACK_BUFFER_ARB 平面绘图
	//缓冲区类型还有很多。。。
    glGenBuffers(1, &bufferObj);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, bufferObj);
    glBufferData(GL_PIXEL_UNPACK_BUFFER_ARB, DIM*DIM * 16, NULL, GL_DYNAMIC_DRAW_ARB);

	//GL_PIXEL_UNPACK_BUFFER_ARB GL_PIXEL_PACK_BUFFER_ARB区别
	//unpack，从缓冲区到opengl，设置后，glDrawPixel，glTexImage2D，glTexSubImage2D的默认来源
	//pack，从opengl到缓冲区，设置后，glReadPixel，glGetTexImage的默认目标
    glGenBuffers(1, &bufferObj1);
    glBindBuffer(GL_PIXEL_PACK_BUFFER_ARB, bufferObj1);
    glBufferData(GL_PIXEL_PACK_BUFFER_ARB, DIM*DIM * 16, NULL, GL_DYNAMIC_DRAW_ARB);

	//把缓冲区绑定CUDA
	//cudaGraphicsMapFlagsNone
	//cudaGraphicsRegisterFlagsReadOnly
	//cudaGraphicsRegisterFlagsWriteDiscard
	cudaGraphicsGLRegisterBuffer(&resource, bufferObj, cudaGraphicsMapFlagsNone);
	cudaGraphicsGLRegisterBuffer(&resource1, bufferObj1, cudaGraphicsMapFlagsNone);

	//Opengl显示图片
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouseFunc);
	init();
    glutMainLoop();
    return 0;
}