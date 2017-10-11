/*
√Ë ˆ
Given two matrix A and B with size N*N (1<=N<=128), compute the multiplication A*B over field 2. We assume that the matrix is a square matrix(N*N) and each number only contains two possible values, {0,1}. Implement the Strassen algorithm for Matrix Multiplication problem, and compare the time and memory performance with grade-school method. 

 ‰»Î
The first line contains only one integer N, which indicates the size of the matrix. Note, N is always a power of 2. 
The following 2N lines describe the matrix A and matrix B respectively. Each line contains N integers and is one row in the matrix. Each element in the matrix is 0 or 1.

 ‰≥ˆ
Output the matrix C = A*B in N lines. Each line is a row of matrix C with N integers. Note, each element in C should be 0 or 1.
*/
#include <stdio.h>
#include <stdlib.h>
int** matmalloc(int n) 
{
	int **p;
	p = (int **)malloc(sizeof(int*)*n);
	int i;
	int *q;
	for (i = 0; i < n; i++)
	{
		q = (int *)malloc(sizeof(int)*n);
		p[i] = q;
	}
	return p;
}
char** cmatmalloc(int n)
{
	char **p;
	p = (char **)malloc(sizeof(char*)*n);
	int i;
	char *q;
	for (i = 0; i < n; i++)
	{
		q = (char *)malloc(sizeof(char)*n);
		p[i] = q;
	}
	return p;
}
void matfree(int ** p, int n) 
{
	int i;
	for (i = 0; i < n; i++)
		free(p[i]);
	free(p);
}
void cmatfree(char ** p, int n)
{
	int i;
	for (i = 0; i < n; i++)
		free(p[i]);
	free(p);
}
int multi(int **a, int **b, int **c, int n) 
{
	int i, j;
	int **a11, **a12, **a21, **a22, **b11, **b12, **b21, **b22;
	int **p, **q, **p1, **p2, **p3, **p4, **p5, **p6, **p7;
	if (n == 1) 
	{
		c[0][0] = a[0][0] * b[0][0];
		return 0;
	}
	a11 = matmalloc(n / 2);a12 = matmalloc(n / 2);a21 = matmalloc(n / 2);a22 = matmalloc(n / 2);
	b11 = matmalloc(n / 2);b12 = matmalloc(n / 2);b21 = matmalloc(n / 2);b22 = matmalloc(n / 2);
	p1 = matmalloc(n / 2);p2 = matmalloc(n / 2);p3 = matmalloc(n / 2);
	p4 = matmalloc(n / 2);p5 = matmalloc(n / 2);p6 = matmalloc(n / 2);
	p7 = matmalloc(n / 2);p = matmalloc(n / 2);q = matmalloc(n / 2);
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
		{
			a11[i][j] = a[0 + i][0 + j];
			a12[i][j] = a[0 + i][n / 2 + j];
			a21[i][j] = a[n / 2 + i][0 + j];
			a22[i][j] = a[n / 2 + i][n / 2 + j];
			b11[i][j] = b[0 + i][0 + j];
			b12[i][j] = b[0 + i][n / 2 + j];
			b21[i][j] = b[n / 2 + i][0 + j];
			b22[i][j] = b[n / 2 + i][n / 2 + j];
		}
	for(i = 0;i < n / 2;i++)
		for (j = 0; j < n / 2; j++)
			p[i][j] = (b12[i][j] + b22[i][j]) % 2;
	multi(a11, p, p1, n / 2);
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			p[i][j] = (a11[i][j] + a12[i][j]) % 2;
	multi(p, b22, p2, n / 2);
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			p[i][j] = (a21[i][j] + a22[i][j]) % 2;
	multi(p, b11, p3, n / 2);
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			p[i][j] = (b11[i][j] + b21[i][j]) % 2;
	multi(a22, p, p4, n / 2);
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
		{
			p[i][j] = (a11[i][j] + a22[i][j]) % 2;
			q[i][j] = (b11[i][j] + b22[i][j]) % 2;
		}
	multi(p, q, p5, n / 2);
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
		{
			p[i][j] = (a12[i][j] + a22[i][j]) % 2;
			q[i][j] = (b21[i][j] + b22[i][j]) % 2;
		}
	multi(p, q, p6, n / 2);
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
		{
			p[i][j] = (a11[i][j] + a21[i][j]) % 2;
			q[i][j] = (b11[i][j] + b12[i][j]) % 2;
		}
	multi(p, q, p7, n / 2);
	for(i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
		{
			c[i][j] = (p2[i][j] + p4[i][j] + p5[i][j] + p6[i][j]) % 2;
			c[i][n / 2 + j] = (p1[i][j] + p2[i][j]) % 2;
			c[n / 2 + i][j] = (p3[i][j] + p4[i][j]) % 2;
			c[n / 2 + i][n / 2 + j] = (p1[i][j] + p3[i][j] + p5[i][j] + p7[i][j]) % 2;
		}
	matfree(q, n / 2);matfree(p, n / 2);matfree(p1, n / 2);
	matfree(p2, n / 2);matfree(p3, n / 2);matfree(p4, n / 2);
	matfree(p5, n / 2);matfree(p6, n / 2);matfree(p7, n / 2);
	matfree(a11, n / 2);matfree(a12, n / 2);matfree(a21, n / 2);matfree(a22, n / 2);
	matfree(b11, n / 2);matfree(b12, n / 2);matfree(b21, n / 2);matfree(b22, n / 2);
	return 0;
}

int main(void) 
{
	int n, i, j;
	int **a, **b, **c;
	char **A, **B, **C;
	scanf("%d\n", &n);
	A = cmatmalloc(n);
	B = cmatmalloc(n);
	for (i = 0; i < n; i++)
		scanf("%s", A[i]);
	for (i = 0; i < n; i++)
		scanf("%s", B[i]);
	a = matmalloc(n);
	b = matmalloc(n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			a[i][j] = A[i][j] - '0';
			b[i][j] = B[i][j] - '0';
		}
	cmatfree(A, n);
	cmatfree(B, n);
	c = matmalloc(n);
	multi(a, b, c, n);
	matfree(a, n);
	matfree(b, n);
	C = cmatmalloc(n + 1);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			C[i][j] = c[i][j] + '0';
	for (i = 0; i < n; i++)
		C[i][n] = '\0';
	matfree(c, n);
	for (i = 0; i < n; i++)
		printf("%s\n", C[i]);
	cmatfree(C, n + 1);
}