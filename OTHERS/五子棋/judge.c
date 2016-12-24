#include <stdio.h>
int judge(int chessboard[15][15]){
	int i, j, sum;
	for (i = 0; i < 15; i++)
		for (j = 0; j < 11; j++){
			sum = 0;
			sum += chessboard[i][j] + chessboard[i][j + 1] + chessboard[i][j + 2] + chessboard[i][j + 3] + chessboard[i][j + 4];
			if (sum == -5){
				printf("Black Win!\n");
				return 1;
			}
			else if (sum == 5){
				printf("White Win!\n");
				return 1;
			}
		}
	for (i = 0; i < 11; i++)
		for (j = 0; j < 15; j++){
			sum = 0;
			sum += chessboard[i][j] + chessboard[i + 1][j] + chessboard[i + 2][j] + chessboard[i + 3][j] + chessboard[i + 4][j];
			if (sum == -5){
				printf("Black Win!\n");
				return 1;
			}
			else if (sum == 5){
				printf("White Win!\n");
				return 1;
			}
		}
	for (i = 0; i < 11; i++)
		for (j = 0; j < 11; j++){
			sum = 0;
			sum += chessboard[i][j] + chessboard[i + 1][j + 1] + chessboard[i + 2][j + 2] + chessboard[i + 3][j + 3] + chessboard[i + 4][j + 4];
			if (sum == -5){
				printf("Black Win!\n");
				return 1;
			}
			else if (sum == 5){
				printf("White Win!\n");
				return 1;
			}
		}
	for (i = 0; i < 11; i++)
		for (j = 0; j < 11; j++){
			sum = 0;
			sum += chessboard[14 - i][j] + chessboard[13 - i][j + 1] + chessboard[12 - i][j + 2] + chessboard[11 - i][j + 3] + chessboard[10 - i][j + 4];
			if (sum == -5){
				printf("Black Win!\n");
				return 1;
			}
			else if (sum == 5){
				printf("White Win!\n");
				return 1;
			}
		}
	return 0;
}
