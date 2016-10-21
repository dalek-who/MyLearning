/*
描述
蛙人使用一套特殊的设备潜水，他有一些装有氧气与氮气的圆筒。根据他想要在水下呆的时间以及他所想下潜的深度，蛙人需要不同数量的氧气及氮气。他有一些可供他支配的圆筒，每个圆筒有其重量以及它所含的气体体积。为了完成任务蛙人需要其中一些圆筒以便获取特定数量的氧气及氮气，那么这些圆筒的最小重量是多少呢？

例子：

蛙人有5个可支配的圆筒描述如下，其中每个圆筒的描述包括：氧气的体积、氮气的体积（以升为单位）、圆筒的重量（以10克为单位）。

3 36 120

10 25 129

5 50 250

1 45 130

4 20 119

如果蛙人需要5升氧气与60升氮气，则他需要两个圆筒的最小总重量是249（第一第二个圆筒或第四第五个圆筒）。

要求读入蛙人需要的氧气数及氮气数，圆筒的数量及每个圆筒的描述，

输入
第一行包括两个整数t、a由一个空格隔开(1<=t<=21,1<=a<=79)，表示完成任务所需的氧气体积及氮气体积。
第二行包括一个整数n(1<=n<=1000)表示可选择的圆筒数量。
以下n行包括每个圆筒的描述：第i+1行包括三个整数ti、ai、wi,(1<=ti<=21,1<=ai<=79,1<=wi<=800)，分别为氧气的体积、氮气的体积以及这个圆筒的重量。

输出
一个整数，表示蛙人为完成任务所需圆筒的最小总重量。
*/
#include <stdio.h>
int min2(int a, int b)
{
	if(a > b)
		return b;
	else return a;
}
int min3(int a, int b, int c)
{
	if(a > c && b > c)
		return c;
	else if(a > b)
		return b;
	else return a;
}
int main(void)
{
	int input[1001][3];
	int num[3];
	int weight[1001][22][80];
	int i, j, k;
	scanf("%d %d", &num[0],&num[1]);
	scanf("%d",&num[2]);
	for(k = 0; k <= num[2]; k++)
	{
	for(i = 0; i <= 21; i++)
		for(j = 0; j <= 79; j++)
			weight[k][i][j] = 800000;
	weight[k][0][0] = 0;
	}
	for(i = 1; i <= num[2]; i++)
	{
		scanf("%d %d %d",&input[i][0],&input[i][1],&input[i][2]);
		for(j = 0; j <= 21; j++)
			for(k = 0; k <= 79; k++)
			{
				if(j < input[i][0] && k < input[i][1])
					weight[i][j][k] = min2( weight[i-1][j][k], weight[i-1][0][0] + input[i][2]);
				else if( j < input[i][0])
					weight[i][j][k] = min2( weight[i-1][j][k], weight[i-1][0][k - input[i][1]] + input[i][2]);
				else if( k < input[i][1])
					weight[i][j][k] = min2( weight[i-1][j][k], weight[i-1][j - input[i][0]][0] + input[i][2]);
				else
					weight[i][j][k] = min2( weight[i-1][j][k], weight[i-1][j - input[i][0]][k - input[i][1]] + input[i][2]);
			}
	}
	printf("%d",weight[num[2]][num[0]][num[1]]);
	return 0;
}