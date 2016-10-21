/*
√Ë ˆ
Find the k-th largest element in an unsorted array A . Note that it is the k-th largest element in the sorted order, not the k-th distinct element. The range of length of A is N (1°‹N°‹1,000,000) and the elements (integer) in A are no larger than 10,000,000. 

Hint: You can use sorting algorithm with O(n log n) time complexity, but a better algorithm for this problem needs only O(n) time. 

 ‰»Î
The first line contains two integers N and k where N is the length of the unsorted array A, and k is the index. The second line gives the unsorted array A.

 ‰≥ˆ
Output a single line with a single integer which is the k-th largest element in the array.
*/
#include<stdio.h>
#define M 1000000
int num[M];
int L[M];
int sort(int left, int right)
{
	if (left >= right)
		return 0;
	int mid = (right + left) / 2;
	sort(left, mid);
	sort(mid + 1, right);
	int i = 0;
	int j = left, k = mid + 1;
	while (i < right - left +1)
	{
		if ((num[j] > num[k] && j <= mid) || k > right)
		{
			L[i] = num[j];
			j++;
		}
		else
		{
			L[i] = num[k];
			k++;
		}
		i++;
	}
	for (i = 0; i < right - left + 1; i++)
		num[left + i] = L[i];
	return 0;
}
int main(void)
{
	int count;
	int th;
	int i;
	scanf("%d", &count);
	scanf("%d", &th);
	for (i = 0; i < count; i++)
	{
		scanf("%d", &num[i]);
	}
	sort(0, count - 1);
	printf("%d", num[th-1]);
	return 0;
}