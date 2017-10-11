int precalc(int chessboard[15][15], int i, int j, int BoW){
	int point, to5, to4, d4, to3, d3, to2, d2;
	point = 0;
	to5 = 0;
	to4 = 0;
	d4 = 0;
	to3 = 0;
	d3 = 0;
	to2 = 0;
	d2 = 0;
	if (i - 4 >= 0 && j - 4 >= 0)
		if (chessboard[i - 4][j - 4] + chessboard[i - 3][j - 3] + chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] == 4 * BoW)to5++;
	if (i - 4 >= 0)
		if (chessboard[i - 4][j] + chessboard[i - 3][j] + chessboard[i - 2][j] + chessboard[i - 1][j] == 4 * BoW)to5++;
	if (i - 4 >= 0 && j + 4 < 15)
		if (chessboard[i - 4][j + 4] + chessboard[i - 3][j + 3] + chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] == 4 * BoW)to5++;
	if (j - 4 >= 0)
		if (chessboard[i][j - 4] + chessboard[i][j - 3] + chessboard[i][j - 2] + chessboard[i][j - 1] == 4 * BoW)to5++;
	if (j + 4 < 15)
		if (chessboard[i][j + 4] + chessboard[i][j + 3] + chessboard[i][j + 2] + chessboard[i][j + 1] == 4 * BoW)to5++;
	if (i + 4 < 15 && j - 4 >= 0)
		if (chessboard[i + 4][j - 4] + chessboard[i + 3][j - 3] + chessboard[i + 2][j - 2] + chessboard[i + 1][j - 1] == 4 * BoW)to5++;
	if (i + 4 < 15)
		if (chessboard[i + 4][j] + chessboard[i + 3][j] + chessboard[i + 2][j] + chessboard[i + 1][j] == 4 * BoW)to5++;
	if (i + 4 < 15 && j + 4 < 15)
		if (chessboard[i + 4][j + 4] + chessboard[i + 3][j + 3] + chessboard[i + 2][j + 2] + chessboard[i + 1][j + 1] == 4 * BoW)to5++;
	if (i - 3 >= 0 && j - 3 >= 0){
		if (i == 3 || j == 3){
			if (chessboard[i - 3][j - 3] + chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] == 3 * BoW)d4++;
		}
		else if (chessboard[i - 3][j - 3] + chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] == 3 * BoW){
			if (chessboard[i - 4][j - 4] == 0)to4++;
			else if (chessboard[i - 4][j - 4] == (-1)*BoW)d4++;
		}
		if (i + 1 < 15 && j + 1 < 15){
			if (chessboard[i - 3][j - 3] + chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] + chessboard[i + 1][j + 1] == 4 * BoW)to5++;
			else if (chessboard[i - 3][j - 3] + chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] + chessboard[i + 1][j + 1] == 3 * BoW)d4++;
		}
	}
	if (i - 3 >= 0){
		if (i == 3){
			if (chessboard[i - 3][j] + chessboard[i - 2][j] + chessboard[i - 1][j] == 3 * BoW)d4++;
		}
		else if (chessboard[i - 3][j] + chessboard[i - 2][j] + chessboard[i - 1][j] == 3 * BoW){
			if (chessboard[i - 4][j] == 0)to4++;
			else if (chessboard[i - 4][j] == (-1)*BoW)d4++;
		}
		if (i + 1 < 15){
			if (chessboard[i - 3][j] + chessboard[i - 2][j] + chessboard[i - 1][j] + chessboard[i + 1][j] == 4 * BoW)to5++;
			else if (chessboard[i - 3][j] + chessboard[i - 2][j] + chessboard[i - 1][j] + chessboard[i + 1][j] == 3 * BoW)d4++;
		}
	}
	if (i - 3 >= 0 && j + 3 < 15){
		if (i == 3 || j == 11){
			if (chessboard[i - 3][j + 3] + chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] == 3 * BoW)d4++;
		}
		else if (chessboard[i - 3][j + 3] + chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] == 3 * BoW){
			if (chessboard[i - 4][j + 4] == 0)to4++;
			else if (chessboard[i - 4][j + 4] == (-1)*BoW)d4++;
		}
		if (i + 1 < 15 && j - 1 >= 0){
			if (chessboard[i - 3][j + 3] + chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] + chessboard[i + 1][j - 1] == 4 * BoW)to5++;
			else if (chessboard[i - 3][j + 3] + chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] + chessboard[i + 1][j - 1] == 3 * BoW)d4++;
		}
	}
	if (j - 3 >= 0){
		if (j == 3){
			if (chessboard[i][j - 3] + chessboard[i][j - 2] + chessboard[i][j - 1] == 3 * BoW)d4++;
		}
		else if (chessboard[i][j - 3] + chessboard[i][j - 2] + chessboard[i][j - 1] == 3 * BoW){
			if (chessboard[i][j - 4] == 0)to4++;
			else if (chessboard[i][j - 4] == (-1)*BoW)d4++;
		}
		if (j + 1 < 15){
			if (chessboard[i][j - 3] + chessboard[i][j - 2] + chessboard[i][j - 1] + chessboard[i][j + 1] == 4 * BoW)to5++;
			else if (chessboard[i][j - 3] + chessboard[i][j - 2] + chessboard[i][j - 1] + chessboard[i][j + 1] == 3 * BoW)d4++;
		}
	}
	if (j + 3 < 15){
		if (j == 11){
			if (chessboard[i][j + 3] + chessboard[i][j + 2] + chessboard[i][j + 1] == 3 * BoW)d4++;
		}
		else if (chessboard[i][j + 3] + chessboard[i][j + 2] + chessboard[i][j + 1] == 3 * BoW){
			if (chessboard[i][j + 4] == 0)to4++;
			else if (chessboard[i][j + 4] == (-1)*BoW)d4++;
		}
		if (j - 1 >= 0){
			if (chessboard[i][j + 3] + chessboard[i][j + 2] + chessboard[i][j + 1] + chessboard[i][j - 1] == 4 * BoW)to5++;
			else if (chessboard[i][j + 3] + chessboard[i][j + 2] + chessboard[i][j + 1] + chessboard[i][j - 1] == 3 * BoW)d4++;
		}
	}
	if (i + 3 < 15 && j - 3 >= 0){
		if (i == 11 || j == 3){
			if (chessboard[i + 3][j - 3] + chessboard[i + 2][j - 2] + chessboard[i + 1][j - 1] == 3 * BoW)d4++;
		}
		else if (chessboard[i + 3][j - 3] + chessboard[i + 2][j - 2] + chessboard[i + 1][j - 1] == 3 * BoW){
			if (chessboard[i + 4][j - 4] == 0)to4++;
			else if (chessboard[i + 4][j - 4] == (-1)*BoW)d4++;
		}
		if (i - 1 >= 0 && j + 1 < 15){
			if (chessboard[i + 3][j - 3] + chessboard[i + 2][j - 2] + chessboard[i + 1][j - 1] + chessboard[i - 1][j + 1] == 4 * BoW)to5++;
			else if (chessboard[i + 3][j - 3] + chessboard[i + 2][j - 2] + chessboard[i + 1][j - 1] + chessboard[i - 1][j + 1] == 3 * BoW)d4++;
		}
	}
	if (i + 3 < 15){
		if (i == 11){
			if (chessboard[i + 3][j] + chessboard[i + 2][j] + chessboard[i + 1][j] == 3 * BoW)d4++;
		}
		else if (chessboard[i + 3][j] + chessboard[i + 2][j] + chessboard[i + 1][j] == 3 * BoW){
			if (chessboard[i + 4][j] == 0)to4++;
			else if (chessboard[i + 4][j] == (-1)*BoW)d4++;
		}
		if (i - 1 >= 0){
			if (chessboard[i + 3][j] + chessboard[i + 2][j] + chessboard[i + 1][j] + chessboard[i - 1][j] == 4 * BoW)to5++;
			else if (chessboard[i + 3][j] + chessboard[i + 2][j] + chessboard[i + 1][j] + chessboard[i - 1][j] == 3 * BoW)d4++;
		}
	}
	if (i + 3 < 15 && j + 3 < 15){
		if (i == 11 || j == 11){
			if (chessboard[i + 3][j + 3] + chessboard[i + 2][j + 2] + chessboard[i + 1][j + 1] == 3 * BoW)d4++;
		}
		else if (chessboard[i + 3][j + 3] + chessboard[i + 2][j + 2] + chessboard[i + 1][j + 1] == 3 * BoW){
			if (chessboard[i + 4][j + 4] == 0)to4++;
			else if (chessboard[i + 4][j + 4] == (-1)*BoW)d4++;
		}
		if (i - 1 >= 0 && j - 1 >= 0){
			if (chessboard[i + 3][j + 3] + chessboard[i + 2][j + 2] + chessboard[i + 1][j + 1] + chessboard[i - 1][j - 1] == 4 * BoW)to5++;
			else if (chessboard[i + 3][j + 3] + chessboard[i + 2][j + 2] + chessboard[i + 1][j + 1] + chessboard[i - 1][j - 1] == 3 * BoW)d4++;
		}
	}
	if (i - 2 >= 0 && j - 2 >= 0){
		if (i == 2 || j == 2){
			if (chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] == 2 * BoW)d3++;
		}
		else if (chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] == 2 * BoW){
			if (chessboard[i - 3][j - 3] == 0)to3++;
			else if (chessboard[i - 3][j - 3] == (-1)*BoW)d3++;
		}
		if (i + 1 < 15 && j + 1 < 15){
			if (chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] + chessboard[i + 1][j + 1] == 3 * BoW)to4++;
			else if (chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] + chessboard[i + 1][j + 1] == 2 * BoW)to3++;
		}
		if (i + 2 < 15 && j + 2 < 15){
			if (chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] + chessboard[i + 1][j + 1] + chessboard[i + 2][j + 2] == 4 * BoW)to5++;
			if (chessboard[i - 2][j - 2] + chessboard[i - 1][j - 1] + chessboard[i + 1][j + 1] + chessboard[i + 2][j + 2] == 3 * BoW){
				if (chessboard[i - 1][j - 1] == 0 || chessboard[i + 1][j + 1] == 0)d4++;
			}
		}
	}
	if (i - 2 >= 0){
		if (i == 2){
			if (chessboard[i - 2][j] + chessboard[i - 1][j] == 2 * BoW)d3++;
		}
		else if (chessboard[i - 2][j] + chessboard[i - 1][j] == 2 * BoW){
			if (chessboard[i - 3][j] == 0)to3++;
			else if (chessboard[i - 3][j] == (-1)*BoW)d3++;
		}
		if (i + 1 < 15){
			if (chessboard[i - 2][j] + chessboard[i - 1][j] + chessboard[i + 1][j] == 3 * BoW)to4++;
			else if (chessboard[i - 2][j] + chessboard[i - 1][j] + chessboard[i + 1][j] == 2 * BoW)to3++;
		}
		if (i + 2 < 15){
			if (chessboard[i - 2][j] + chessboard[i - 1][j] + chessboard[i + 1][j] + chessboard[i + 2][j] == 4 * BoW)to5++;
			if (chessboard[i - 2][j] + chessboard[i - 1][j] + chessboard[i + 1][j] + chessboard[i + 2][j] == 3 * BoW){
				if (chessboard[i - 1][j] == 0 || chessboard[i + 1][j] == 0)d4++;
			}
		}
	}
	if (i - 2 >= 0 && j + 2 < 15){
		if (i == 2 || j == 12){
			if (chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] == 2 * BoW)d3++;
		}
		else if (chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] == 2 * BoW){
			if (chessboard[i - 3][j + 3] == 0)to3++;
			else if (chessboard[i - 3][j + 3] == (-1)*BoW)d3++;
		}
		if (i + 1 < 15 && j - 1 >= 0){
			if (chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] + chessboard[i + 1][j - 1] == 3 * BoW)to4++;
			else if (chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] + chessboard[i + 1][j - 1] == 2 * BoW)to3++;
		}
		if (i + 2 < 15 && j - 2 >= 0){
			if (chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] + chessboard[i + 1][j - 1] + chessboard[i + 2][j - 2] == 4 * BoW)to5++;
			if (chessboard[i - 2][j + 2] + chessboard[i - 1][j + 1] + chessboard[i + 1][j - 1] + chessboard[i + 2][j - 2] == 3 * BoW){
				if (chessboard[i - 1][j + 1] == 0 || chessboard[i + 1][j - 1] == 0)d4++;
			}
		}
	}
	if (j - 2 >= 0){
		if (j == 2){
			if (chessboard[i][j - 2] + chessboard[i][j - 1] == 2 * BoW)d3++;
		}
		else if (chessboard[i][j - 2] + chessboard[i][j - 1] == 2 * BoW){
			if (chessboard[i][j - 3] == 0)to3++;
			else if (chessboard[i][j - 3] == (-1)*BoW)d3++;
		}
		if (j + 1 < 15){
			if (chessboard[i][j - 2] + chessboard[i][j - 1] + chessboard[i][j + 1] == 3 * BoW)to4++;
			else if (chessboard[i][j - 2] + chessboard[i][j - 1] + chessboard[i][j + 1] == 2 * BoW)to3++;
		}
		if (j + 2 < 15){
			if (chessboard[i][j - 2] + chessboard[i][j - 1] + chessboard[i][j + 1] + chessboard[i][j + 2] == 4 * BoW)to5++;
			if (chessboard[i][j - 2] + chessboard[i][j - 1] + chessboard[i][j + 1] + chessboard[i][j + 2] == 3 * BoW){
				if (chessboard[i][j - 1] == 0 || chessboard[i][j + 1] == 0)d4++;
			}
		}
	}
	if (j + 2 < 15){
		if (j == 12){
			if (chessboard[i][j + 2] + chessboard[i][j + 1] == 2 * BoW)d3++;
		}
		else if (chessboard[i][j + 2] + chessboard[i][j + 1] == 2 * BoW){
			if (chessboard[i][j + 3] == 0)to3++;
			else if (chessboard[i][j + 3] == (-1)*BoW)d3++;
		}
		if (j - 1 >= 0){
			if (chessboard[i][j + 2] + chessboard[i][j + 1] + chessboard[i][j - 1] == 3 * BoW)to4++;
			else if (chessboard[i][j + 2] + chessboard[i][j + 1] + chessboard[i][j - 1] == 2 * BoW)to3++;
		}
	}
	if (i + 2 < 15 && j - 2 >= 0){
		if (i == 12 || j == 2){
			if (chessboard[i + 2][j - 2] + chessboard[i + 1][j - 1] == 2 * BoW)d3++;
		}
		else if (chessboard[i + 2][j - 2] + chessboard[i + 1][j - 1] == 2 * BoW){
			if (chessboard[i + 3][j - 3] == 0)to3++;
			else if (chessboard[i + 3][j - 3] == (-1)*BoW)d3++;
		}
		if (i - 1 >= 0 && j + 1 < 15){
			if (chessboard[i + 2][j - 2] + chessboard[i + 1][j - 1] + chessboard[i - 1][j + 1] == 3 * BoW)to4++;
			else if (chessboard[i + 2][j - 2] + chessboard[i + 1][j - 1] + chessboard[i - 1][j + 1] == 2 * BoW)to3++;
		}
	}
	if (i + 2 < 15){
		if (i == 12){
			if (chessboard[i + 2][j] + chessboard[i + 1][j] == 2 * BoW)d3++;
		}
		else if (chessboard[i + 2][j] + chessboard[i + 1][j] == 2 * BoW){
			if (chessboard[i + 3][j] == 0)to3++;
			else if (chessboard[i + 3][j] == (-1)*BoW)d3++;
		}
		if (i - 1 >= 0){
			if (chessboard[i + 2][j] + chessboard[i + 1][j] + chessboard[i - 1][j] == 3 * BoW)to4++;
			else if (chessboard[i + 2][j] + chessboard[i + 1][j] + chessboard[i - 1][j] == 2 * BoW)to3++;
		}
	}
	if (i + 2 < 15 && j + 2 < 15){
		if (i == 12 || j == 12){
			if (chessboard[i + 2][j + 2] + chessboard[i + 1][j + 1] == 2 * BoW)d3++;
		}
		else if (chessboard[i + 2][j + 2] + chessboard[i + 1][j + 1] == 2 * BoW){
			if (chessboard[i + 3][j + 3] == 0)to3++;
			else if (chessboard[i + 3][j + 3] == (-1)*BoW)d3++;
		}
		if (i - 1 >= 0 && j - 1 >= 0){
			if (chessboard[i + 2][j + 2] + chessboard[i + 1][j + 1] + chessboard[i - 1][j - 1] == 3 * BoW)to4++;
			else if (chessboard[i + 2][j + 2] + chessboard[i + 1][j + 1] + chessboard[i - 1][j - 1] == 2 * BoW)to3++;
		}
	}
	if (i - 1 >= 0 && j - 1 >= 0){
		if (i == 1 || j == 1){
			if (chessboard[i - 1][j - 1] == BoW)d2++;
		}
		else if (chessboard[i - 1][j - 1] == BoW){
			if (chessboard[i - 2][j - 2] == 0)to2++;
			else if (chessboard[i - 2][j - 2] == (-1)*BoW)d2++;
		}
		if (i + 1 < 15 && j + 1 < 15){
			if (i == 13 || j == 13){
				if (chessboard[i - 1][j - 1] + chessboard[i][j] + chessboard[i + 1][j + 1] == 3 * BoW){
					if (chessboard[i - 2][j - 2] == 0)d3++;
				}
			}
			else if (i == 1 || j == 1){
				if (chessboard[i - 1][j - 1] + chessboard[i][j] + chessboard[i + 1][j + 1] == 3 * BoW){
					if (chessboard[i + 2][j + 2] == 0)d3++;
				}
			}
			else if (chessboard[i - 1][j - 1] + chessboard[i][j] + chessboard[i + 1][j + 1] == 3 * BoW){
				if (chessboard[i - 2][j - 2] == 0 && chessboard[i + 2][j + 2] == 0)to3++;
				else if (chessboard[i - 2][j - 2] == (-1)*BoW || chessboard[i + 2][j + 2] == (-1)*BoW)d3++;
			}
		}
	}
	if (i - 1 >= 0){
		if (i == 1){
			if (chessboard[i - 1][j] == BoW)d2++;
		}
		else if (chessboard[i - 1][j] == BoW){
			if (chessboard[i - 2][j] == 0)to2++;
			else if (chessboard[i - 2][j] == (-1)*BoW)d2++;
		}
		if (i + 1 < 15){
			if (i == 13){
				if (chessboard[i - 1][j] + chessboard[i][j] + chessboard[i + 1][j] == 3 * BoW){
					if (chessboard[i - 2][j] == 0)d3++;
				}
			}
			else if (i == 1){
				if (chessboard[i - 1][j] + chessboard[i][j] + chessboard[i + 1][j] == 3 * BoW){
					if (chessboard[i + 2][j] == 0)d3++;
				}
			}
			else if (chessboard[i - 1][j] + chessboard[i][j] + chessboard[i + 1][j] == 3 * BoW){
				if (chessboard[i - 2][j] == 0 && chessboard[i + 2][j] == 0)to3++;
				else if (chessboard[i - 2][j] == (-1)*BoW || chessboard[i + 2][j] == (-1)*BoW)d3++;
			}
		}
	}
	if (i - 1 >= 0 && j + 1 < 15){
		if (i == 1 || j == 13){
			if (chessboard[i - 1][j + 1] == BoW)d2++;
		}
		else if (chessboard[i - 1][j + 1] == BoW){
			if (chessboard[i - 2][j + 2] == 0)to2++;
			else if (chessboard[i - 2][j + 2] == (-1)*BoW)d2++;
		}
		if (i + 1 < 15 && j - 1 >= 0){
			if (i == 13 || j == 1){
				if (chessboard[i - 1][j + 1] + chessboard[i][j] + chessboard[i + 1][j - 1] == 3 * BoW){
					if (chessboard[i - 2][j + 2] == 0)d3++;
				}
			}
			else if (i == 1 || j == 13){
				if (chessboard[i - 1][j + 1] + chessboard[i][j] + chessboard[i + 1][j - 1] == 3 * BoW){
					if (chessboard[i + 2][j - 2] == 0)d3++;
				}
			}
			else if (chessboard[i - 1][j + 1] + chessboard[i][j] + chessboard[i + 1][j - 1] == 3 * BoW){
				if (chessboard[i - 2][j + 2] == 0 && chessboard[i + 2][j - 2] == 0)to3++;
				else if (chessboard[i - 2][j + 2] == (-1)*BoW || chessboard[i + 2][j - 2] == (-1)*BoW)d3++;
			}
		}
	}
	if (j - 1 >= 0){
		if (j == 1){
			if (chessboard[i][j - 1] == BoW)d2++;
		}
		else if (chessboard[i][j - 1] == BoW){
			if (chessboard[i][j - 2] == 0)to2++;
			else if (chessboard[i][j - 2] == (-1)*BoW)d2++;
		}
		if (j + 1 < 15){
			if (j == 13){
				if (chessboard[i][j - 1] + chessboard[i][j] + chessboard[i][j + 1] == 3 * BoW){
					if (chessboard[i][j - 2] == 0)d3++;
				}
			}
			else if (j == 1){
				if (chessboard[i][j - 1] + chessboard[i][j] + chessboard[i][j + 1] == 3 * BoW){
					if (chessboard[i][j + 2] == 0)d3++;
				}
			}
			else if (chessboard[i][j - 1] + chessboard[i][j] + chessboard[i][j + 1] == 3 * BoW){
				if (chessboard[i][j - 2] == 0 && chessboard[i][j + 2] == 0)to3++;
				else if (chessboard[i][j - 2] == (-1)*BoW || chessboard[i][j + 2] == (-1)*BoW)d3++;
			}
		}
	}
	if (j + 1 < 15){
		if (j == 13){
			if (chessboard[i][j + 1] == BoW)d2++;
		}
		else if (chessboard[i][j + 1] == BoW){
			if (chessboard[i][j + 2] == 0)to2++;
			else if (chessboard[i][j + 2] == (-1)*BoW)d2++;
		}
	}
	if (i + 1 < 15 && j - 1 >= 0){
		if (i == 13 || j == 1){
			if (chessboard[i + 1][j - 1] == BoW)d2++;
		}
		else if (chessboard[i + 1][j - 1] == BoW){
			if (chessboard[i + 2][j - 2] == 0)to2++;
			else if (chessboard[i + 2][j - 2] == (-1)*BoW)d2++;
		}
	}
	if (i + 1 < 15){
		if (i == 13){
			if (chessboard[i + 1][j] == BoW)d2++;
		}
		else if (chessboard[i + 1][j] == BoW){
			if (chessboard[i + 2][j] == 0)to2++;
			else if (chessboard[i + 2][j] == (-1)*BoW)d2++;
		}
	}
	if (i + 1 < 15 && j + 1 < 15){
		if (i == 13 || j == 13){
			if (chessboard[i + 1][j + 1] == BoW)d2++;
		}
		else if (chessboard[i + 1][j + 1] == BoW){
			if (chessboard[i + 2][j + 2] == 0)to2++;
			else if (chessboard[i + 2][j + 2] == (-1)*BoW)d2++;
		}
	}
	if (to5 > 0)point += 100;
	if (to4 > 0 || d4 > 1 || (d4 > 0 && to3 > 0))point += 90;
	if (to3 > 1)point += 80;
	if (to3 > 0 && d3 > 0)point += 70;
	if (d4 == 1 && to3 == 0)point += 60;
	if (to3 == 1 && d3 == 0)point += 60;
	if (to2 > 1)point += 40;
	if (d3 > 0 && to3 == 0)point += 30;
	if (to2 == 1)point += 20;
	if (d2 > 0)point += 10;
	return point;
}
