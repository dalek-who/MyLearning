#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[200];
char train[2][10];
char tmp[6];
int queue[2] = {0};
int departing[2] = {0};
int arriving[2] = {0};
int day[2][2] = {0};
FILE *read, *write;
int same()
{
	int i = 0;
	while(train[0][i] != '\0' || train[1][i] != '\0')
	{
		if(train[0][i] != train[1][i])
			return 0;
		i++;
	}
	return 1;
}
int main(void)
{
	read = fopen("Stepx-Database1-1.csv", "r");
	write = fopen("Stepx-Database1-2.csv", "w");
	int i, j, k, count, len, M;
	printf("How many lines?\n");
	scanf("%d",&M);
	train[0][0] = '2';
	for(i = 0; i < M; i++)
	{
		fgets(str, 200, read);
		len = strlen(str);
		count = 0;
		for(j = 0; j < len; j++)
		{
			if(str[j] == '|')
				count++;
			else if(count == 1)
			{
				k = 0;
				while(str[j] != '|' && j < len)
				{
					train[1][k] = str[j];
					j++;
					k++;					
				}
				count++;
				train[1][k] = '\0';
			}
			else if(count == 16)
			{
				k = 0;
				while(str[j] != '|' && j < len)
				{
					tmp[k] = str[j];
					j++;
					k++;
				}
				tmp[k] = '\0';
				arriving[1] = atoi(tmp);
				count++;
				j++;
				k = 0;
				while(str[j] != '|' && j < len)
				{
					tmp[k] = str[j];
					j++;
					k++;
				}
				tmp[k] = '\0';
				departing[1] = atoi(tmp);
				break;
			}
		}
		
		str[len - 1] = '\0';
		if(!same())
		{
			for(k = 0; k < 10; k++)
			{
				train[0][k] = train[1][k];
			}
			day[0][0] = 0;
			day[0][1] = day[0][0];
			day[1][0] = 0;
			day[1][1] = 0;
		}
		else 
		{
			if(arriving[1] < departing[0])
				day[1][0] = day[0][1] + 1;
			else day[1][0] = day[0][1];
			if(departing[1] < arriving[1])
				day[1][1] = day[1][0] + 1;
			else day[1][1] = day[1][0];
			day[0][1] = day[1][1];
		}
		arriving[0] = arriving[1];
		departing[0] = departing[1];
		fprintf(write,"%s|%d|%d\n", str, day[1][0], day[1][1]);
	}
	fclose(read);fclose(write);
	return 0;
}
