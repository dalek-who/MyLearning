/*
描述
Alice and Bob learn geometry these days. One day, their teacher gives them a piece of paper and asks them to draw a rectangle in this paper. Bob thinks this task is too easy, so he draws several points in the paper. He asks Alice to make a rectangle satisfying the following two conditions: 1. there are no points located inside the rectangle (the point can be located in the edge of the rectangle); 2. the edge of the rectangle is either parallel or vertical to the edge of the paper. Your task is to find the maximum area of the rectangle.

输入
The piece of paper is rectangle with size n*m (0<=n,m<=30000). There are k points in the paper. You can assume the coordinates of left-bottom corner/right-up corner are (0,0)/(n,m) and the coordinates of all points are integers. 
The first line of input contains three integers: n, m, k. 
In the following k lines, each line contains two integers indicating the coordinate of the k-th point.

There are five test points satisfying k<=100.
There are eight test points satisfying k<=200.
In all ten test points, k<=5000.

输出
Your task is to output the maximum area of rectangle without any point insider it.
*/
#include <stdio.h>
typedef struct{
	short x;
	short y;
}point_t;
point_t point[5002];
point_t L[5002];
int B[5002];
int Q[5002];
int n,m,k;
int sortx(int left, int right, int * num)
{
	if (left >= right)
		return 0;
	int mid = (right + left) / 2;
	sortx(left, mid, num);
	sortx(mid + 1, right, num);
	int i = 0;
	int j = left, k = mid + 1;
	while (i < right - left +1)
	{
		if ((num[j] > num[k] && j <= mid) || k > right)
		{
			Q[i] = num[j];
			j++;
		}
		else
		{
			Q[i] = num[k];
			k++;
		}
		i++;
	}
	for (i = 0; i < right - left + 1; i++)
		num[left + i] = Q[i];
	return 0;
}
int sort(int left, int right, point_t *num)
{
	if (left >= right)
		return 0;
	int mid = (right + left) / 2;
	sort(left, mid, num);
	sort(mid + 1, right, num);
	int i = 0;
	int j = left, k = mid + 1;
	while (i < right - left +1)
	{
		if ((num[j].x > num[k].x && j <= mid) || k > right)
		{
			L[i].x = num[j].x;
			L[i].y = num[j].y;
			j++;
		}
		else
		{
			L[i].x = num[k].x;
			L[i].y = num[k].y;
			k++;
		}
		i++;
	}
	for (i = 0; i < right - left + 1; i++)
	{
		num[left + i].x = L[i].x;
		num[left + i].y = L[i].y;
	}
	return 0;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	int i, j, r, a, b, c, d, max = 0;
	for(i = 1; i <= k; i++)
		scanf("%d%d", &point[i].x, &point[i].y);
	sort(1, k, point);
	point[0].x = n;
	point[k + 1].x = 0;
	for(i = 0; i < k+2; i++)
	{
		a = point[i].x;
		if(a*m < max) break;
		c = m;
		for(j = i + 1; j < k + 2; j++)
		{
			b = point[j].x;
			if(a*c < max) break;
			if((a-b)*c < max) continue;
			for(r = i + 1; r < j; r++)
				B[r - i] = point[r].y;
			B[0] = m;
			B[j - i] = 0;
			sortx(1, j - i - 1, B);
			c = 0;
			for(r = 0; r < j - i; r++)
			{
				B[r] -= B[r + 1];
				if(B[r] > c) c = B[r];
			}
			if(max < (a-b)*c)
				max = (a-b)*c;
		}
	}
	printf("%d\n",max);
}