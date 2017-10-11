int five(int chessboard[15][15], int i, int j, int n, int m,int BoW){
	if (i + 4 * n <= 14 && j + 4 * m <= 14 && j + 4 * m >= 0 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i + 3 * n][j + 3 * m] + chessboard[i + 4 * n][j + 4 * m] == 4 * BoW)
		return 1;
	else if (i + 3 * n <= 14 && i - n >= 0 && j + 3 * m <= 14 && j + 3 * m >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i + 3 * n][j + 3 * m] + chessboard[i - n][j - m] == 4 * BoW)
		return 1;
	else if (i + 2 * n <= 14 && i - 2 * n >= 0 && j + 2 * m <= 14 && j + 2 * m >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 4 * BoW)
		return 1;
	else if (i + 1 * n <= 14 && i - 3 * n >= 0 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i + n][j + m] + chessboard[i - 3 * n][j - 3 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 4 * BoW)
		return 1;
	else if (i - 4 * n >= 0 && j - 4 * m >= 0 && j - 4 * m <= 14 && chessboard[i - 4 * n][j - 4 * m] + chessboard[i - 3 * n][j - 3 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 4 * BoW)
		return 1;
	return 0;
}

int activefour(int chessboard[15][15], int i, int j, int n, int m,int BoW){
	if (i + 4 * n <= 14 && i - n >= 0 && j + 4 * m <= 14 && j + 4 * m >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i + 3 * n][j + 3 * m] == 3 * BoW && chessboard[i - n][j - m] == 0 && chessboard[i + 4 * n][j + 4 * m] == 0)
		return 1;
	else if (i + 3 * n <= 14 && i - 2 * n >= 0 && j + 3 * m <= 14 && j + 3 * m >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i - n][j - m] == 3 * BoW && chessboard[i - 2 * n][j - 2 * m] == 0 && chessboard[i + 3 * n][j + 3 * m] == 0)
		return 1;
	else if (i + 2 * n <= 14 && i - 2 * n >= 0 && j + 2 * m <= 14 && j + 2 * m >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i + n][j + m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 3 * BoW && chessboard[i - 3 * n][j - 3 * m] == 0 && chessboard[i + 2 * n][j + 2 * m] == 0)
		return 1;
	else if (i + 1 * n <= 14 && i - 3 * n >= 0 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 4 * m >= 0 && j - 4 * m <= 14 && chessboard[i - 3 * n][j - 3 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 3 * BoW && chessboard[i - 4 * n][j - 4 * m] == 0 && chessboard[i + n][j + m] == 0)
		return 1;
	return 0;
}

int deathfour(int chessboard[15][15], int i, int j, int n, int m, int BoW){
	if (i + 3 * n <= 14 &&  j + 4 * m <= 14 && j + 4 * m >= 0 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i + 3 * n][j + 3 * m] == 3 * BoW && ((i - n >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i - n][j - m] == 0) || (i + 4 * n <= 14 && j + 4 * m <= 14 && j + 4 * m >= 0 && chessboard[i + 4 * n][j + 4 * m] == 0)))
		return 1;
	else if (i + 2 * n <= 14 && i - 1 * n >= 0 && j + 2 * m <= 14 && j + 2 * m >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i - n][j - m] == 3 * BoW && ((i - 2 * n >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i - 2 * n][j - 2 * m] == 0) || (i + 3 * n <= 14 && j + 3 * m <= 14 && j + 3 * m >= 0 && chessboard[i + 3 * n][j + 3 * m] == 0)))
		return 1;
	else if (i + 1 * n <= 14 && i - 2 * n >= 0 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i + n][j + m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 3 * BoW && ((i - 3 * n >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i - 3 * n][j - 3 * m] == 0) || (i + 2 * n <= 14 && j + 2 * m <= 14 && j + 2 * m >= 0 && chessboard[i + 2 * n][j + 2 * m] == 0)))
		return 1;
	else if (i - 3 * n >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i - 3 * n][j - 3 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 3 * BoW && ((i - 4 * n >= 0 && j - 4 * m >= 0 && j - 4 * m <= 14 && chessboard[i - 4 * n][j - 4 * m] == 0) || (i + 1 * n <= 14 && j + 1 * m <= 14 && j + 1 * m >= 0 && chessboard[i + n][j + m] == 0)))
		return 1;
	if (i + 4 * n <= 14 && j + 4 * m <= 14 && j + 4 * m >= 0 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i + 3 * n][j + 3 * m] + chessboard[i + 4 * n][j + 4 * m] == 3 * BoW)
		return 1;
	else if (i + 3 * n <= 14 && i - n >= 0 && j + 3 * m <= 14 && j + 3 * m >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i + 3 * n][j + 3 * m] + chessboard[i - n][j - m] == 3 * BoW)
		return 1;
	else if (i + 2 * n <= 14 && i - 2 * n >= 0 && j + 2 * m <= 14 && j + 2 * m >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 3 * BoW)
		return 1;
	else if (i + 1 * n <= 14 && i - 3 * n >= 0 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i + n][j + m] + chessboard[i - 3 * n][j - 3 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 3 * BoW)
		return 1;
	else if (i - 4 * n >= 0 && j - 4 * m >= 0 && j - 4 * m <= 14 && chessboard[i - 4 * n][j - 4 * m] + chessboard[i - 3 * n][j - 3 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 3 * BoW)
		return 1;
	return 0;
}

int activethree(int chessboard[15][15], int i, int j, int n, int m, int BoW){
	if (i + 3 * n <= 14 && i - n >= 0 && j + 3 * m <= 14 && j + 3 * m >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] == 2 * BoW && chessboard[i - n][j - m] == 0 && chessboard[i + 3 * n][j + 3 * m] == 0 && ( (i - 2 * n >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i - 2 * n][j - 2 * m] == 0) || (i + 4 * n <= 14 && j + 4 * m >= 0 && j + 4 * m <= 14 && chessboard[i + 4 * n][j + 4 * m] == 0) ) )
		return 1;
	else if (i + 2 * n <= 14 && i - 2 * n >= 0 && j + 2 * m <= 14 && j + 2 * m >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i + n][j + m] + chessboard[i - n][j - m] == 2 * BoW && chessboard[i - 2 * n][j - 2 * m] == 0 && chessboard[i + 2 * n][j + 2 * m] == 0 && ( (i - 3 * n >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i - 3 * n][j - 3 * m] == 0) || (i + 3 * n <= 14 && j + 3 * m >= 0 && j + 3 * m <= 14 && chessboard[i + 3 * n][j + 3 * m] == 0) ) )
		return 1;
	else if (i + 1 * n <= 14 && i - 3 * n >= 0 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 2 * BoW && chessboard[i - 3 * n][j - 3 * m] == 0 && chessboard[i + 1 * n][j + 1 * m] == 0 && ( (i - 4 * n >= 0 && j - 4 * m >= 0 && j - 4 * m <= 14 && chessboard[i - 4 * n][j - 4 * m] == 0) || (i + 2 * n <= 14 && j + 2 * m >= 0 && j + 2 * m <= 14 && chessboard[i + 2 * n][j + 2 * m] == 0) ) )
		return 1;
	if (i + 4 * n <= 14 && i - n >= 0 && j + 4 * m <= 14 && j + 4 * m >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i + 3 * n][j + 3 * m] == 2 * BoW && chessboard[i - n][j - m] == 0 && chessboard[i + 4 * n][j + 4 * m] == 0)
		return 1;
	else if (i + 3 * n <= 14 && i - 2 * n >= 0 && j + 3 * m <= 14 && j + 3 * m >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i - n][j - m] == 2 * BoW && chessboard[i - 2 * n][j - 2 * m] == 0 && chessboard[i + 3 * n][j + 3 * m] == 0)
		return 1;
	else if (i + 2 * n <= 14 && i - 2 * n >= 0 && j + 2 * m <= 14 && j + 2 * m >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i + n][j + m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 2 * BoW && chessboard[i - 3 * n][j - 3 * m] == 0 && chessboard[i + 2 * n][j + 2 * m] == 0)
		return 1;
	else if (i + 1 * n <= 14 && i - 3 * n >= 0 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 4 * m >= 0 && j - 4 * m <= 14 && chessboard[i - 3 * n][j - 3 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 2 * BoW && chessboard[i - 4 * n][j - 4 * m] == 0 && chessboard[i + n][j + m] == 0)
		return 1;
	return 0;
}

int deaththree(int chessboard[15][15], int i, int j, int n, int m, int BoW){
	if (i + 2 * n <= 14 && j + 2 * m <= 14 && j + 2 * m >= 0 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] == 2 * BoW && (i - 3 * n >= 0 && j - 3 * m >= 0 && j - 3 * m <= 0 && chessboard[i - n][j - m] == 0 && chessboard[i - 2 * n][j - 2 * m] == 0 && chessboard[i - 3 * n][j - 3 * m] == 0) || (i + 5 * m <= 14 && j + 5 * m <= 14 && j + 5 * m >= 0 && chessboard[i + 3 * n][j + 3 * m] == 0 && chessboard[i + 4 * n][j + 4 * m] == 0 && chessboard[i + 5 * n][j + 5 * m] == 0) )
		return 1;
	else if (i + 1 * n <= 14 && i - 1 * n <= 14 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 1 * m <= 14 && j - 1 * m >= 0 && chessboard[i - n][j - m] + chessboard[i + 1 * n][j + 1 * m] == 2 * BoW && (i - 4 * n >= 0 && j - 4 * m >= 0 && j - 4 * m <= 0 && chessboard[i - 4 * n][j - 4 * m] == 0 && chessboard[i - 2 * n][j - 2 * m] == 0 && chessboard[i - 3 * n][j - 3 * m] == 0) || (i + 4 * m <= 14 && j + 4 * m <= 14 && j + 4 * m >= 0 && chessboard[i + 3 * n][j + 3 * m] == 0 && chessboard[i + 4 * n][j + 4 * m] == 0 && chessboard[i + 2 * n][j + 2 * m] == 0) )
		return 1;
	else if (i - 2 * n <= 14 && j - 2 * m <= 14 && j - 2 * m >= 0 && chessboard[i - n][j - m] + chessboard[i - 2 *n][j - 2 *m] == 2 * BoW && (i - 5 * n >= 0 && j - 5 * m >= 0 && j - 5 * m <= 0 && chessboard[i - 4 * n][j - 4 * m] == 0 && chessboard[i - 5 * n][j - 5 * m] == 0 && chessboard[i - 3 * n][j - 3 * m] == 0) || (i + 3 * m <= 14 && j + 3 * m <= 14 && j + 3 * m >= 0 && chessboard[i + 3 * n][j + 3 * m] == 0 && chessboard[i + 1 * n][j + 1 * m] == 0 && chessboard[i + 2 * n][j + 2 * m] == 0) )
		return 1;
	else if (i - 2 * n <= 14 && j - 2 * m <= 14 && j - 2 * m >= 0 && chessboard[i - n][j - m] + chessboard[i - 2 *n][j - 2 *m] == 2 * BoW && (i - 5 * n >= 0 && j - 5 * m >= 0 && j - 5 * m <= 0 && chessboard[i - 4 * n][j - 4 * m] == 0 && chessboard[i - 5 * n][j - 5 * m] == 0 && chessboard[i - 3 * n][j - 3 * m] == 0) || (i + 3 * m <= 14 && j + 3 * m <= 14 && j + 3 * m >= 0 && chessboard[i + 3 * n][j + 3 * m] == 0 && chessboard[i + 1 * n][j + 1 * m] == 0 && chessboard[i + 2 * n][j + 2 * m] == 0) )
		return 1;
	if (i + 3 * n <= 14 &&  j + 4 * m <= 14 && j + 4 * m >= 0 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i + 3 * n][j + 3 * m] == 2 * BoW && ((i - n >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i - n][j - m] == 0) || (i + 4 * n <= 14 && j + 4 * m <= 14 && j + 4 * m >= 0 && chessboard[i + 4 * n][j + 4 * m] == 0)))
		return 1;
	else if (i + 2 * n <= 14 && i - 1 * n >= 0 && j + 2 * m <= 14 && j + 2 * m >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i + n][j + m] + chessboard[i + 2 * n][j + 2 * m] + chessboard[i - n][j - m] == 2 * BoW && ((i - 2 * n >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i - 2 * n][j - 2 * m] == 0) || (i + 3 * n <= 14 && j + 3 * m <= 14 && j + 3 * m >= 0 && chessboard[i + 3 * n][j + 3 * m] == 0)))
		return 1;
	else if (i + 1 * n <= 14 && i - 2 * n >= 0 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i + n][j + m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 2 * BoW && ((i - 3 * n >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i - 3 * n][j - 3 * m] == 0) || (i + 2 * n <= 14 && j + 2 * m <= 14 && j + 2 * m >= 0 && chessboard[i + 2 * n][j + 2 * m] == 0)))
		return 1;
	else if (i - 3 * n >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i - 3 * n][j - 3 * m] + chessboard[i - 2 * n][j - 2 * m] + chessboard[i - n][j - m] == 2 * BoW && ((i - 4 * n >= 0 && j - 4 * m >= 0 && j - 4 * m <= 14 && chessboard[i - 4 * n][j - 4 * m] == 0) || (i + 1 * n <= 14 && j + 1 * m <= 14 && j + 1 * m >= 0 && chessboard[i + n][j + m] == 0)))
		return 1;
	return 0;
}

int activetwo(int chessboard[15][15], int i, int j, int n, int m, int BoW){
	if (i + 2 * n <= 14 && i - n >= 0 && j + 2 * m <= 14 && j + 2 * m >= 0 && j - 1 * m >= 0 && j - 1 * m <= 14 && chessboard[i + n][j + m] == BoW && chessboard[i - n][j - m] == 0 && chessboard[i + 2 * n][j + 2 * m] == 0 && ( (i - 2 * n >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i - 2 * n][j - 2 * m] == 0) || (i + 3 * n <= 14 && j + 3 * m >= 0 && j + 3 * m <= 14 && chessboard[i + 3 * n][j + 3 * m] == 0) ) )
		return 1;
	else if (i + 1 * n <= 14 && i - 2 * n >= 0 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i - n][j - m] == BoW && chessboard[i - 2 * n][j - 2 * m] == 0 && chessboard[i + 1 * n][j + 1 * m] == 0 && ( (i - 3 * n >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i - 3 * n][j - 3 * m] == 0) || (i + 2 * n <= 14 && j + 2 * m >= 0 && j + 2 * m <= 14 && chessboard[i + 2 * n][j + 2 * m] == 0) ) )
		return 1;
	return 0;
}

int deathtwo(int chessboard[15][15], int i, int j, int n, int m, int BoW){
	if (i + n <= 14 && j + m <= 14 && j + m >= 0 && chessboard[i + n][j + m] == BoW && ( (i - 2 * n >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i - n][j - m] == 0 && chessboard[i - 2 * n][j - 2 * m] == 0) || (i + 3 * n <= 14 && j + 3 * m >= 0 && j + 3 * m <= 14 && chessboard[i + 2 * n][j + 2 * m] == 0 && chessboard[i + 3 * n][j + 3 * m] == 0) ) )
		return 1;
	else if (i + 1 * n <= 14 && i - 2 * n >= 0 && j + 1 * m <= 14 && j + 1 * m >= 0 && j - 2 * m >= 0 && j - 2 * m <= 14 && chessboard[i - n][j - m] == BoW && chessboard[i - 2 * n][j - 2 * m] == 0 && chessboard[i + 1 * n][j + 1 * m] == 0 && ( (i - 3 * n >= 0 && j - 3 * m >= 0 && j - 3 * m <= 14 && chessboard[i - 3 * n][j - 3 * m] == 0) || (i + 2 * n <= 14 && j + 2 * m >= 0 && j + 2 * m <= 14 && chessboard[i + 2 * n][j + 2 * m] == 0) ) )
		return 1;
	return 0;
}

int death(int chessboard[15][15], int i, int j, int n, int m, int BoW){
	if (chessboard[i + n][j + m] == BoW)
		return 1;
	if (chessboard[i - n][j - m] == BoW)
		return 1;
	return 0;
}
	
int calc(int chessboard[15][15], int i, int j, int BoW){
	int sum = 0;
	sum += 10000*(five(chessboard, i, j, 0, 1, BoW) + five(chessboard, i, j, 1, 0, BoW) + five(chessboard, i, j, 1, 1, BoW) + five(chessboard, i, j, 1, -1, BoW));
	sum += 1500*(activefour(chessboard, i, j, 0, 1, BoW) + activefour(chessboard, i, j, 1, 0, BoW) + activefour(chessboard, i, j, 1, 1, BoW) + activefour(chessboard, i, j, 1, -1, BoW));
	sum += 6*6*6*(deathfour(chessboard, i, j, 0, 1, BoW) + deathfour(chessboard, i, j, 1, 0, BoW) + deathfour(chessboard, i, j, 1, 1, BoW) + deathfour(chessboard, i, j, 1, -1, BoW));
	sum += 6*6*6*(activethree(chessboard, i, j, 0, 1, BoW) + activethree(chessboard, i, j, 1, 0, BoW) + activethree(chessboard, i, j, 1, 1, BoW) + activethree(chessboard, i, j, 1, -1, BoW));
	sum += 6*6*(deaththree(chessboard, i, j, 0, 1, BoW) + deaththree(chessboard, i, j, 1, 0, BoW) + deaththree(chessboard, i, j, 1, 1, BoW) + deaththree(chessboard, i, j, 1, -1, BoW));
	sum += 6*6*(activetwo(chessboard, i, j, 0, 1, BoW) + activetwo(chessboard, i, j, 1, 0, BoW) + activetwo(chessboard, i, j, 1, 1, BoW) + activetwo(chessboard, i, j, 1, -1, BoW));
	sum += 6*(deathtwo(chessboard, i, j, 0, 1, BoW) + deathtwo(chessboard, i, j, 1, 0, BoW) + deathtwo(chessboard, i, j, 1, 1, BoW) + deathtwo(chessboard, i, j, 1, -1, BoW));
	sum += 1*(death(chessboard, i, j, 0, 1, BoW) + death(chessboard, i, j, 1, 0, BoW) + death(chessboard, i, j, 1, 1, BoW) + death(chessboard, i, j, 1, -1, BoW));
	return sum;
}

	
	
