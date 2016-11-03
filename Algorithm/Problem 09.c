\*
ÃèÊö
There are n piles of cards on the table (1<=n<=10000). The total number of cards is the multiples of n. Now, you can move cards from one pile to another pile step by step. In each step, you will choose one pile, and are allowed to move the cards in this pile to its neighboring piles, that is, cards in pile i can be moved to pile i-1 or pile i+1. You want every pile have the same number of cards. Find the minimum number of steps you need.

For example, there are 4 piles initially: 9 8 17 6. You can reach 10 10 10 10 by 3 steps. Step 1: move 4 cards from pile 3 to pile 4. Step 2: move 3 cards from pile 3 to pile 2. Step 3: move 1 card from pile 2 to pile 1.

ÊäÈë
The input contains two lines. The first line contains one integer n. 
The second line contains n positive integers which represent the numbers of cards in these n piles.

Êä³ö
Output exactly one integer which is the minimum number of steps you need.
*\
#include <stdio.h>
int p[10001];
int n;
int sum = 0, num, step = 0;
int sub(int a, int b){
	if(a == b)
		return 0;
	else return 1;
}
int main(void){
	scanf("%d", &n);
	int i;
	for(i = 1; i <= n; i++){
		scanf("%d", &p[i]);
		sum = sum + p[i];
	}
	num = sum / n;
	for(i = 1; i < n; i++){
		step = step + sub(p[i],num);
		p[i+1]=p[i]+p[i+1]-num;
	}
	printf("%d",step);
	return 0;
}
