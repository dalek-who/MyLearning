#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
	int chessboard[15][15] = { 0 }, input[2], T = 0, begin =0, step, time1, time2;
	/*step表示步数,T若为0玩家是黑棋,若为1玩家是白棋;在chessboard里面,0表示没有棋子,1表示白子,-1表示黑子*/
	char track[226][4], order[4];
	int judge(int chessboard[15][15]), calc(int chessboard[15][15], int i, int j, int BoW), open(int chessboard[15][15], int i, int j), draw(int chessboard[15][15], int p, int q), fivetwo(int chessboard[15][15], int T, int input[2], char x), jarvis(int BoW, int n), scan(int input[2], int i, int j);

int scan(int input[2], int i, int j){
	char x[4],y;
	time_t start, end;
	start = time(NULL);
	if(i) scanf("%s", x);
	else strcpy(x, track[j]);
	strcpy(track[j], x);
	end = time(NULL);
	if (step == 3 && T == 1 && order[0] != 'l' && (x[0] == 'h' || x[0] == 'H') && (x[1] == 'h' || x[1] == 'H') && strlen(x) == 2){
		T = 1 - T;
	}/*三手可换*/
	if (x[0] == 'z' && x[1] == 'z' && strlen(x) == 2 && step - begin > 1){
		step--;
		scan(input, 0, step);
		chessboard[input[0]][input[1]] = 0;
		step--;
		scan(input, 0, step);
		chessboard[input[0]][input[1]] = 0;
		scan(input, 0, step-1);
		draw(chessboard, input[1], input[0]);
		printf("Retractation of success, your turn:  ");
		scan(input, 1, step);
		return 0;
	}
	if (x[0] >= 'a' && x[0] <= 'o')
		input[0] = x[0] - 'a';
	else if (x[0] >= 'A' && x[0] <= 'O')
		input[0] = x[0] - 'A';
	else input[0] = -1;
	if (strlen(x) == 2 && x[1] >= 'a' && x[1] <= 'f')
		input[1] = 5 + 'a' - x[1];
	else if (strlen(x) == 2 && x[1] >= 'A' && x[1] <= 'F')
		input[1] = 5 + 'A' - x[1];
	else if (strlen(x) == 2 && x[1] >= '1' && x[1] <= '9')
		input[1] = 14 + '1' - x[1];
	else if (strlen(x) == 3 && x[1] == '1' && x[2] >= '0' && x[2] <= '5')
		input[1] = 4 + '1' - x[2];
	else input[1] = -1;
	if(i == -1 && y != 'z') input[1] = 1;
	if(i) time2 =end - start;
	if(i) time1 += time2;
	return 0;
}

int main(void){
	int i, j, flag = 0, all = 0;
	char f[5];
	printf("choose the game pattern:\n                        0.specify opening: z + d/i + number\n                        1.human-computer: c\n                        2.human-human: h\n                        3.load track.txt: l\n");
	scanf("%s", order);
	FILE *fp = fopen("track.txt", "r");
	if (order[0] == 'l'){
		fscanf(fp, "%s", track[0]);
		while(strlen(track[all]) != 0){
			fscanf(fp, "%s", track[all]);
			all++;
		}
	}
	else if (order[0] == 'c'){
		printf("0:choose the black  1:choose the white  2:random\n");
		scanf("%d", &T);
		srand (time (NULL) );
		if (T == 2)
			T = rand()%2;
	}
	else if (order[0] == 'z'){
		order[0] = 'c';
		if (order[1] == 'd') i = 1;
		else if (order[1] == 'i') i = 2;
		if (strlen(order) == 3) j = order[2] - '0';
		else if (strlen(order) == 4) j = 10 + order[3] - '0';
		open(chessboard, i, j);
		if (chessboard[7][7] == -1) begin += 3;
		T = 1;/*指定开局里,因为若想要变成黑棋,可以打hh,因此默认玩家为白棋,*/
	}
	else {
		printf("invalid inputs\n");
		return 0;
	}
	step = begin;
	draw(chessboard,7,7);
	while (!flag && step < 225){
		if (step == 4 && order[0] != 'l'){
			printf ("do you want to 5/2?: y/n\n");
			while(getchar()!='\n');
			scanf("%s", f);
			if( (f[0] == 'y' || f[0] == 'Y') && strlen(f) == 1){
				fivetwo(chessboard, T, input, order[0]);
				step += 2;
			}
		}
		if (step != 0) printf("The last step is %s. Now it's %d step. The total time is %ds, and the last step costs %ds.\n", track[step-1], step + 1, time1, time2);
		printf("If you want to retract a false move, you can type zz, if you want to retract two or more, you can type twice or more.\n");
		if (step == 3) printf("If you want to change the color, you can type hh.\n");
		if (step % 2 == T){
			if (T == 1) printf("The white's turn:  ");
			else printf("The Black's turn:  ");
			if (order[0] != 'l') scan(input, 1, step);
			else if (order[0] == 'l') scan(input, 0, step);
			if (input[0] != -1 && input[1] != -1 && chessboard[input[0]][input[1]] == 0){
				chessboard[input[0]][input[1]] = 2* T - 1;
				draw(chessboard,input[1],input[0]);
			}
			else if (step % 2 == T){
				printf("invalid inputs,please try again\n");
				step--;
			}
		}
		else if (step % 2 != T){
			if (T == 0) printf("The white's turn:  ");
			else printf("The Black's turn:  ");
			if (order[0] == 'c' && step != 0) jarvis(1 - 2 * T, step);
			else if (order[0] == 'c' && step == 0){
				track[0][0] = 'h';
				track[0][1] = '8';
				scan(input, 0, step);
				chessboard[7][7] = 1 - 2 * T;
				}
			else if (order[0] == 'h') scan(input, 1, step);
			else if (order[0] == 'l') scan(input, 0, step);
			if( (order[0] == 'h' || order[0] == 'l') && input[0] != -1 && input[1] != -1 && chessboard[input[0]][input[1]] == 0) chessboard[input[0]][input[1]] = 1 - 2 * T;
			draw(chessboard, input[1], input[0]);
		}
		step++;
		if (step == all) flag = 1;
		flag = judge(chessboard);
		if (flag != 0) printf("The final step is %s, the total time is %ds.\n", track[step-1], time1);
	}
	if (step == 226) printf("No Space!\n");
	if (order[0] != 'l'){
		freopen("track.txt","w",stdout);
		for(i = begin; i < step - 1; i++)
			printf("%s\n", track[i]);
	}
	return 0;
}

int jarvis(int BoW, int n){
	srand((unsigned)time(NULL));
	int i, j, s, t, r, max;
	int points[15][15] = { 0 }, points1[15][15] = { 0 }, points2[15][15] = { 0 };
	int record[225][2] = { 0 };
	for (i = 0; i < 15; i++)
		for (j = 0; j < 15; j++)
			if (chessboard[i][j] == 0){
				points[i][j] += calc(chessboard, i, j, BoW);
				points[i][j] += calc(chessboard, i, j, (-1)*BoW);
				points1[i][j] += calc(chessboard, i, j, BoW);
				points2[i][j] += calc(chessboard, i, j, (-1)*BoW);
			}
	max = 0;
	t = 0;
	for (i = 0; i < 15; i++)
		for (j = 0; j < 15; j++){
			if (points[i][j]>max){
				max = points[i][j];
				record[0][0] = i;
				record[0][1] = j;
				t = 1;
			}
			else if (points[i][j] == max){
				record[t][0] = i;
				record[t][1] = j;
				t++;
			}
		}
	max = 0;
	r = 0;
	if (t>1){
		for (i = 0; i < t; i++){
			if (points1[record[i][0]][record[i][1]]>max){
				max = points1[record[i][0]][record[i][1]];
				record[0][0] = record[i][0];
				record[0][1] = record[i][1];
				r = 1;
			}
			else if (points1[record[i][0]][record[i][1]] == max){
				record[r][0] = record[i][0];
				record[r][1] = record[i][1];
				r++;
			}
		}
	}
	if(r == 0) s = 0;
	else s = rand() % r + 0;
	track[n][0] = 'a' + record[s][0];
	if(record[s][1] < 6) track[n][1] = 5 + 'a' - record[s][1];
	else track[n][1] = 14 + '1' - record[s][1];
	chessboard[record[s][0]][record[s][1]] = BoW;
	scan(input, 0, step);
	return 0;
}
