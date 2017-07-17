/*
描述
Suppose we have n integers. We want to combine them in a row so as to obtain a largest number. For example, consider three integers 13, 312, 343. We can combine them to get 13312343, 13343312, etc. The largest number we can obtain is 34331213.

输入
The input contains two lines. The first line contains one integer n (1<=n<=1000). The second line contains n integers and each integer is in the range [1,500].

输出
The output contains one line which is the largest number we can obtain.
*/
#include <stdio.h>
int input[1001][2];
int n;
int L[1001][2];
int main()
{  
	scanf("%d",&n);
	int i, j;
	int c;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &c);
		if(c < 10)
		{
			input[i][1] = 1;
			input[i][0] = c;
		}
		else if (c < 100)
		{
			input[i][1] = 2;
			input[i][0] = c;
		}
		else 
		{
			input[i][1] = 3;
			input[i][0] = c;		
		}
	}
	sort(0, n - 1);
	for(i = 0; i < n; i++)
		printf("%d", input[i][0]);
	return 0;
	
}
int getnumber(int j, int k)
{
	int i = 0;
	int num1, num2;
	num1 = input[j][0];
	num2 = input[k][0];
	i = 0;
	while(i < input[k][1])
	{
		num1 = num1 * 10;
		i++;
	}
	num1+= input[k][0];
	i = 0;
	while(i < input[j][1])
	{
		num2 = num2 * 10;
		i++;
	}
	num2+= input[j][0];
	if(num1 > num2)
		return 1;
	else return 0;
}
int sort(int left, int right)
{
	if (left >= right)
		return 0;
	int mid = (right + left) / 2;
	sort(left, mid);
	sort(mid + 1, right);
	int i = 0;
	int j = left, k = mid + 1;
	while (i < right - left + 1)
	{
		if ((getnumber(j, k) && j <= mid) || k > right)
		{
			L[i][0] = input[j][0];
			L[i][1] = input[j][1];
			j++;
		}
		else
		{
			L[i][0] = input[k][0];
			L[i][1] = input[k][1];
			k++;
		}
		i++;
	}
	for (i = 0; i < right - left + 1; i++)
	{
		input[left + i][0] = L[i][0];
		input[left + i][1] = L[i][1];
	}
	return 0;
}
