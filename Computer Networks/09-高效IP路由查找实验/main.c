#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "normal.h"
#include "advanced.h"

int time_cost(){
	FILE *fp;
	if((fp = fopen("forwarding-table.txt", "rt")) == NULL){
		printf("File Open Error\n");
		return 0;
	}
	char row[32];
	u32 ip;
	u16 port;
	u8 length;
	int number = 0;
	clock_t tStart, tFinish; 

    tStart = clock();
	while(!feof(fp)){
		number++;
		fgets(row, 32, fp);
		if(row[0] == '\0'){
			break;
		}
		scanf_row(row, &ip, &length, &port);
		row[0] = '\0';
	}
	tFinish = clock();
	totaltime = tFinish - tStart;
	fclose(fp);
	return 0 ;
}
int main(int argc, char const *argv[]){
	if(argc != 2){
		printf("./search mode\n");
		printf("mode 1 for normal search\n");
		printf("mode 2 for advanced search\n");
		return 0;
	}

	int mode;
	mode = atoi(argv[1]);
	space = 0;

	time_cost();
	if(mode == 1){
		normal();
	}else{
		advanced();
	}
	
	space = space / 1024;
	printf("average time: %ld ns\ntotal space: %d KB\n", totaltime, space);
	return 0;
}