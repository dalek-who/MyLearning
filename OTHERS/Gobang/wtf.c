#include <stdio.h>
int open(int chessboard[15][15], int i, int j){
	if (i == 1){
		chessboard[7][7] = -1;
		chessboard[7][6] = 1;
		switch (j){
		case 1: chessboard[7][5] = -1; break; 
		case 2: chessboard[8][5] = -1; break;
		case 3: chessboard[9][5] = -1; break;
		case 4: chessboard[8][6] = -1; break;
		case 5: chessboard[9][6] = -1; break;
		case 6: chessboard[8][7] = -1; break;
		case 7: chessboard[9][7] = -1; break;
		case 8: chessboard[7][8] = -1; break;
		case 9: chessboard[8][8] = -1; break;
		case 10: chessboard[9][8] = -1; break;
		case 11: chessboard[7][9] = -1; break;
		case 12: chessboard[8][9] = -1; break;
		case 13: chessboard[9][9] = -1; break;
		default: chessboard[7][7] = 0; chessboard[7][6] = 0; break;
		}
	}
	else if (i == 2){
		chessboard[7][7] = -1;
		chessboard[8][6] = 1;
		switch (j){
		case 1: chessboard[9][5] = -1; break;
		case 2: chessboard[9][6] = -1; break;
		case 3: chessboard[9][7] = -1; break;
		case 4: chessboard[9][8] = -1; break;
		case 5: chessboard[9][9] = -1; break;
		case 6: chessboard[8][7] = -1; break;
		case 7: chessboard[8][8] = -1; break;
		case 8: chessboard[8][9] = -1; break;
		case 9: chessboard[7][8] = -1; break;
		case 10: chessboard[7][9] = -1; break;
		case 11: chessboard[6][8] = -1; break;
		case 12: chessboard[6][9] = -1; break;
		case 13: chessboard[5][9] = -1; break;
		default: chessboard[7][7] = 0; chessboard[8][6] = 0; break;
		}
	}
	return 0;
}

int fivetwo(int chessboard[15][15], int T, int input[2], char x){
	int i, j, k, point[2][3];
	if (T == 0){
		printf("The fifth step:  ");
		scan(input, 1, 4);
		chessboard[input[0]][input[1]] = 2 * T - 1;
		j = input[0];
		k = input[1];
		draw(chessboard);
		printf("The sixth step:  ");
		scan(input, 1, 5);
		chessboard[input[0]][input[1]] = 2 * T - 1;
	}
	else if (T == 1){
		printf("The fifth step:  ");
		if (x == 'c'){
			jarvis(1 - 2 * T, 4);
			scan(input, 0, 4);
			draw(chessboard);
		}
		else if (x == 'h'){
			scan(input, 1, 4);
			chessboard[input[0]][input[1]] = 1 - 2 * T;
		}
		j = input[0];
		k = input[1];
		printf("The sixth step:  ");
		if (x == 'c'){
			jarvis(1 - 2 * T, 5);
			scan(input, 0, 5);
		}
		else if (x == 'h'){
			scan(input, 1, 5);
			chessboard[input[0]][input[1]] = 1 - 2 * T;
		}
	}
	draw(chessboard, input[1], input[0]);
	if (x == 'h' || (x == 'c' && T == 1) ){
		printf("choose the fifth step or the sixth step: 5 or 6    (5-%c%d   6-%c%d)\n", j + 'a', k, input[0] + 'a', input[1]);
		scanf("%d",&i);
		if (i == 5){
			chessboard[j][k] = chessboard[j][k] * -1;
			draw(chessboard, k, j);
		}
		else if (i == 6){
			chessboard[input[0]][input[1]] = chessboard[input[0]][input[1]] * -1;
			draw(chessboard, input[1], input[0]);
		}
	}
	else if (x == 'c' && T == 0){
		point[0][0] == calc(chessboard, j, k, 1);
		point[0][0] += calc(chessboard, j, k, -1);
		point[0][1] == calc(chessboard, j, k, 1);
		point[0][2] == calc(chessboard, j, k, -1);
		point[1][0] == calc(chessboard, input[0], input[1], 1);
		point[1][0] += calc(chessboard, input[0], input[1], -1);
		point[1][1] == calc(chessboard, input[0], input[1], 1);
		point[1][2] == calc(chessboard, input[0], input[1], -1);
		if (point[0][0] > point[1][0] || (point[0][0] == point[1][0] && point[0][1] >= point[1][1]) ){
			chessboard[j][k] = chessboard[j][k] * -1;
			draw(chessboard, k, j);
			printf("The computer chooses the fifth step.\n");
		}
		else if (point[0][0] < point[1][0] || (point[0][0] == point[1][0] && point[0][1] < point[1][1])){
			chessboard[input[0]][input[1]] = chessboard[input[0]][input[1]] * -1;
			draw(chessboard, input[1], input[0]);
			printf("The computer chooses the sixth step.\n");
		}
	}
	return 0;
}
int draw(int chessboard[15][15], int p, int q){
	/*┏  ✜ ┓┗ ┛┣  ┫   ┳ ┻  ╋  ╍ ╏ ☢ ✪✂✉☎☏ ┌ └ ┐ ┘*/
	int i, j;
	printf("\ec");
	for (i = 0; i < 15; i++){
		printf("  ");
		for (j = 0; j < 15; j++){
			if (i == 0 && i == p && j == q && j == 14) printf("┌   ┐   ");
			else if (i == 0 && i == p && j == q) printf("┌   ");
			else if (i == p && j == q && j == 14) printf("┌ ╏ ┐   ");
			else if (i == p && j == q) printf("┌ ╏ ");
			else if (i == p && j == q + 1) printf("┐ ╏ ");
			else if (i == p + 1 && j == q && j == 14) printf("└ ╏ ┘   ");
			else if (i == p + 1 && j == q) printf("└ ╏ ");
			else if (i == p + 1 && j == q + 1) printf("┘ ╏ ");
			else if (i == 0) printf("    ");
			else printf("  ╏ ");
		}
	printf("\n");
	if (i < 6)
		printf("%2d%c",15 - i,5 - i + 'a');
	else printf(" %d ",15 - i);
	for (j = 0; j < 15; j++)
		switch (chessboard[j][i]){
		case 1: if (j != 0 && j != 14) printf(" ☎ ╍");
			else if (j == 14) printf(" ☎ ");
			else if (j == 0) printf(" ☎ ╍"); break;
		case -1: if (j != 0 && j != 14) printf(" ✉ ╍");
			else if (j == 14) printf(" ✉ ");
			else if (j == 0) printf(" ✉ ╍"); break;
		case 0: if (i == 0 && j == 0) printf(" ┏╍╍");
			else if (i == 0 && j == 14) printf("╍┓");
			else if (i == 14 && j == 0) printf(" ┗╍╍");
			else if (i ==14 && j == 14) printf("╍┛");
			else if (i == 0) printf("╍┳╍╍");
			else if (i == 14) printf("╍┻╍╍");
			else if (j == 0) printf(" ┣╍╍");
			else if (j == 14) printf("╍┫");
			else printf("╍╋╍╍"); break;
		default: break;
		}
	printf("\n");
	}
	printf("  ");
	for (i = 0; i < 15; i++){
		if (p == 14 && i == q) printf("└ %c ",i + 'A');
		else if (p == 14 && i == q + 1) printf("┘ %c ",i + 'A');
		else printf("  %c ",i + 'A');
		}
	printf("\n");
}
