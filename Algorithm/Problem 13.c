/*
描述
Consider a grid with size M * N, the classical game setting is to cover it with cards with size 1 * 2. One day, Alice and Bob would like to play this game, but Alice thinks it is too easy to bob. So she makes some holes on the grid. See the following example.

p1.png

Bob’s task is still to cover the grid with cards with size 1*2. Here is an example of valid solution

p2.png

and some examples of invalid solution. Because you cannot cover a card with another, cover some hole or leave some place uncovered.

p3.png  p4.png  p5.png

Your task is to help Bob to decide whether or not the grid can be covered according to the rules above.

输入
There are 3 integers m, n, k (0 < m, n <= 32, 0 <= K <= m * n), the number of rows, column and holes, in the first line. 
In the next k lines, there is a pair of integers (x, y) which represents a hole in the x-th row, the y-th column.

输出
If the grid can be covered, output "YES". Otherwise, output "NO".
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 2500
int capbility[L][L];
int backup[L][L] = {0};
int distance[L]; 
int a[L], b, c;
int Point, Head, Tail, MAXFLOW;
int current[L];
int min(int x, int y)
{
    return (x < y) ? x: y;
}
int BFS()
{
    int i,j;
    memset(distance, 0xff, sizeof(distance)); 
    distance[1] = 0;
    b = 0;
    c = 1;
    a[1] = 1;
    while(b < c)
    {
        j = a[++b];
        for (i = 1; i <= Point; i++)
            if (distance[i] < 0 && capbility[j][i] > 0)
            {
                distance[i] = distance[j] + 1; 
                a[++c] = i;
            }
    }
    if(distance[Point] > 0)
        return 1;
    else
        return 0;
}
int dinic(int x,int low)
{
    int i, flow;
    if (x == Tail)
        return low;
    for(i = current[x]; i <= Point; i++)
    {
        current[x] = i;
        if (capbility[x][i] > 0 && distance[i] == distance[x] + 1) 
        {
            flow = dinic(i, min(low, capbility[x][i]));
            if(flow)
            {
                capbility[x][i] -= flow;
                capbility[i][x] += flow;
                return flow;
            }
        }
    }
    return 0;
}
int main()
{
    int row, col, hole, i, j, k, add;
    scanf("%d%d%d",&row, &col, &hole);
	if((row*col-hole)%2==1){
		printf("NO");
		return 0;}
    for(i = 0; i <= row * col-1; i++)
    {
	if((i/col+i%col)%2 ==0)
	capbility[1][1 + i * 2 + 1] = 1;
	if(i < col * (row -1))
		capbility[1 + i * 2 + 2][1 + (i+col) * 2 + 1] = 1;
	if(i % col != col - 1)
		capbility[1 + i * 2 + 2][1 + (i+1) * 2 + 1] = 1;
	if(i >= col)
		capbility[1 + i * 2 + 2][1 + (i-col) * 2 + 1] = 1;
	if(i % col != 0)
		capbility[1 + i * 2 + 2][1 + (i-1) * 2 + 1] = 1;
	capbility[1 + i * 2 + 1][1 + i * 2 + 2] = 1;
	if((i/col+i%col)%2!=0)
	capbility[1 + i * 2 + 2][1 + 2*row*col + 1] = 1;
    }
    for(i = 1; i <= hole; i++)
    {
        scanf("%d%d", &j, &k);
	capbility[1 + (j*col-col+k)*2 - 1][1 + (j*col-col+k)*2] = 0;
    }
    Head = 1; Tail = 1 + 2*row*col + 1; Point = 1 + 2*row*col + 1;
        MAXFLOW = 0;
        while(BFS())
        {
            memset(current, 0, sizeof(current));
            while(add = dinic(Head ,0x7fffffff))
                MAXFLOW += add; 
        }//dinic
	if(MAXFLOW == (row*col-hole)/2)
		printf("YES\n");
	else printf("NO\n");
	//printf("%d",MAXFLOW);
}