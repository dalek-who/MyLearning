/*
√Ë ˆ
Recall the problem of finding the number of inversions. As in the course, we are given a sequence of n numbers a1; °§ °§ °§ ; an, which we assume are all distinct, and we define an inversion to be a pair i < j such that ai > aj.

We motivated the problem of counting inversions as a good measure of how different two orderings are. However, one might feel that this measure is too sensitive. Let°Øs call a pair a significant inversion if i < j and ai> 3aj. Given an O(n log n) algorithm to count the number of significant inversions between two orderings.

The array contains N elements(1<=N<=100,000). All elements are range from 1 to 1,000,000,000.

 ‰»Î
Line1 : The first line contains an integer N, which represents the number of elements.
Line 2: given the unsorted array and elements are split by space.

 ‰≥ˆ
Output a single integer which is the number of pairs of significant inversions.
*/
#include <stdio.h>
long a[100000],b[100000];
int inversions(int left, int right)
{
    int num = 0, k;
    if(left >= right)
        return 0;
    if(left == right - 1)
        if(a[left] > a[right])
    	{
        	k = a[left];
        	a[left] = a[right];
        	a[right] = k;
        	if(a[right] > 3 * a[left])
	        	return 1;
        	else
        		return 0;
   		}
    	else return 0;
    int mid = (left + right) / 2;
    num = num + inversions(left, mid) + inversions(mid + 1, right);
    int i = left, j = mid + 1;
    for(k = left; k <= right; k++)
        b[k] = a[k];
    while(j <= right)
    {
        for(k = i; k <= mid; k++)
        	if(b[k] > 3 * b[j])
        	{
               	num = num + mid - k + 1;
              	j++;
             	i = k;
            	break;
            }
        if(k > mid && b[mid] <= 3 * b[j])
            break;
    }
    i = left; j = mid + 1;
    for(k = left; k <= right; k++)
    {
        if((b[i] < b[j] && i <= mid) || j > right)
        {
            a[k] = b[i];
            i++;
        }
        else 
        {
            a[k] = b[j];
            j++;
        }
    }
   	return num;
}
int main(void)
{
    int i;
    scanf("%d", &i);
    int j;
    for(j = 0; j < i; j++)
        scanf("%d", &a[j]);
    printf("%d",inversions(0, i-1));
    return 0;
}