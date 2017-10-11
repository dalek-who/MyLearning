/*
纳什均衡
<输入>
5
0 1 -1 1 -1
-1 0 1 -1 1
1 -1 0 1 -1
-1 1 -1 0 1
1 -1 1 -1 0
<输出>
glpk的输入
*/
#include <stdio.h>
int number[20][20];
int main(void)
{
	printf("/* Variables */\n");
	int line;
	scanf("%d",&line);
	int i, j;
	for(i = 0; i < line; i++)
		for(j = 0; j < line; j++)
		{
			scanf("%d",&number[i][j]);
		}
	for(i = 0; i < line; i++)
		printf("var p%d >= 0;\n", i);
	
	printf("var payoff;\n");
	
	printf("\n/* Object function */\n");

	printf("maximize pay: payoff;\n");

	printf("\n/* Constrains */\n");
	for(i = 0; i < line; i++)
	{
		printf("s.t. con%d: ", i);
		for(j = 0; j < line - 1; j++)
		{
			printf("%d*p%d + ", number[j][i], j);
		}
		printf("%d*p%d >= payoff;\n", number[line - 1][i], line - 1);
	}
	printf("s.t. con%d: ", line);
	for(i = 0; i < line - 1; i++)
		printf("p%d + ", i);
	printf("p%d = 1;\n", line - 1);
	printf("\nend;");
}
