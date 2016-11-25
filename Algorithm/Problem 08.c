/*
描述
Given a directed graph G =< V;E >. Each edge e =< i; j > has a distance d(i,j).We want to calculate the length of the shortest path from a single source node s to a destination node t.

输入
The first line of the input contains four integers: number of nodes n (1<=n<=500), number of edges m, source node s, destination node t. 
After the first line, there are m lines which indicate m edges in the graph. In each line, there are three integers i,j, dij. It means there is an edge from node I to node j with distance dij. 1<=i,j<=n, 1<=dij<=500.

输出
The length of the shortest path from s to t. If there is no path from s to t, output -1.
*/
#include <stdio.h>
int d[501][501] = {0};
int n,m,s,t;
int min(int a, int b){
	if(a < b) return a;
	else return b;
}
int main(void){
	scanf("%d %d %d %d", &n, &m, &s,&t);
	int i,j,k;
	int a,b,c;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			d[i][j]=250000;
	for(i = 1; i <= n; i++)
		d[i][i] = 0;
	for(i = 1; i <= m; i++){
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = c;
	}
	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
	if(d[s][t] != 250000)
		printf("%d", d[s][t]);
	else printf("-1");
	return 0;
}
