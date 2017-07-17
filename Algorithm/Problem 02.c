/*
描述
Two lovely frogs Alice and Bob live by a river. There are several stones in this river. Every morning, they go to the other side of the river to have fun. They cross the river by jumping from one stone to another. One day, Alice decides to play tricks on Bob. She plans to remove some stones so that there is no “easy jump” for Bob to across the river any more. But she has no idea which stones she should remove. She needs your help.

The width of the river is an integer L((1≤L≤1,000,000,000). We treat the river as a one-dimensional line segment, with two endpoints A (two frog’s home) and B (the other side of the river). Among the river, there are N stones (0≤N≤50,000). The distance from the i-th stone to side A is Di (0<Di<L). Alice would like to remove M stones in the river (0≤M≤N) so that with the rest of the stones, the minimum distance among all possible jumps for Bob is the largest.

Hint: use divide-and-conquer technique to search the answer. 

输入
The first line contains three integers L, N and M. The second line gives the positions of N stones. No two stones share the same position.

输出
Output a single line with a single integer which is the maximum of the minimum distance among all possible jumps after removing M stones. In the example, Alice should remove stones with distance 2 and 14. After removing these two stones, the minimum distance of jumps is 4, and there are two jumps with distance 4: from 17 to 21, and from 21 to 25.
*/
#include <stdio.h>
#define M 50000
int stone[M+1];
int sto[M+1];
int Num, Length, m;
int sort(int left, int right)
{
	if (left >= right)
		return 0;
	int mid = (right + left) / 2;
	sort(left, mid);
	sort(mid + 1, right);
	int i = left;
	int j = left, k = mid + 1;
	for(i = left; i <= right; i++)
		if ((stone[j] < stone[k] && j <= mid) || k > right)
		{
			sto[i] = stone[j];
			j++;
    	}
		else
		{
			sto[i] = stone[k];
			k++;
		}
	for (i = left; i <= right; i++)
		stone[i] = sto[i];
	return 0;
}
int judge(int length, int num)
{
    int i = 0, j = 1;
	while(j <= Num + 1 && Length - stone[i] >= num * length)
    {
        if(stone[j] - stone [i] >= length)
        {
            i = j;
            num--;
        }
        j++;
    }
    if(num <= 0)
        return 1;
    else return 0;
}
int main(void)
{
	int num, length, i;
	scanf("%d %d %d", &Length, &Num, &m);
	num = Num - m + 1;
    stone[0] = 0;
	for (i = 1; i <= Num; i++)
		scanf("%d", &stone[i]);
    stone[Num + 1] = Length;
	sort(1, Num);
	length = Length / num;
    int low , high;
    low = 1;
    high = length;
	while ( low != length )
    {
        if(judge(length, num))
            low = length;
        else high = length;
        length = ( low + high ) / 2;
    }
	printf("%d", length);
	return 0;
}