/*
ÃèÊö
A numeric sequence of ai is ordered if a1 < a2< ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK<= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.

ÊäÈë
The first line of input contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000000

Êä³ö
Output a single integer - the length of the longest ordered subsequence of the given sequence.
*/
#include <stdio.h>
#include <stdlib.h>
int opt[10000000];
int main(void)
{
	int i, num, count, flag, head, tail, mid;
	scanf("%d", &num);
	int string[1000000];
	for(i = 0; i < num; i++)
	{
		scanf("%d", &string[i]);
	}
	opt[0] = string[0];
	count = 1; 
	for(i = 1; i < num; i++)
	{
		head = 0;
		tail = count - 1;
		mid = (head + tail) / 2;
		flag = 0;
		if(string[i] > opt[tail])
		{
			opt[count] = string[i];
			count++;
		}
		else if(string[i] < opt[0])
			opt[0] = string[i];
		else
        {
            flag = 1;
            while(flag)
            {
                if(opt[mid] > string[i])
                    tail = mid;
                else if(opt[mid] < string[i])
                    head = mid;
                else if(opt[mid] == string[i])
                {
                    head = mid;
                    tail = mid;
                }
                mid = (head + tail) / 2;
                if(head + 1 >= tail)
                    flag = 0;
            }
            opt[tail] = string[i];
        }
	}
	printf("%d", count);
	return 0;
}