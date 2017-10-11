描述
Given a directed graph G=(V, E). Each edge e has a capacity c(e). Given two special points source s and sink t. Output the value of maximum flow from s to t. 

输入
The first line contains four integers (n,m,s,t) where n is the number of nodes, m is the number of edges, s is source node and t is sink node. In the following m lines, each line contains three integers (i, j, c) indicating a directed edge from node i to node j with capacity c.
In the test cases, we have 1<=n<=300, 0 <= m <= n*(n-1) / 2 for all points. We have capacity c <= 1000 for 7 test points, but for the other 3 test points, the capacity might be as high as 500,000. Note there may have duplicate edges.

输出
You should output one integer which is the value of maximum flow.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int capbility[400][400]; 
int distance[400]; 
int a[4000], b, c;
int Point, Edge, Head, Tail, MAX;
int current[400];
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
    int i, j, head, tail, flow, add;
    scanf("%d%d%d%d", &Point, &Edge, &Head, &Tail);
    memset(capbility, 0, sizeof(capbility));
    for (i = 1;i <= Edge;i++)
    {
        scanf("%d%d%d", &head, &tail, &flow);
          capbility[head][tail] += flow;
    }
    MAX = 0;
    while(BFS())
    {
        memset(current, 0, sizeof(current));
        while(add = dinic(Head ,0x7fffffff))
            MAX += add; 
    }
    printf("%d\n",MAX);
}