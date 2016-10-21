/*
√Ë ˆ
Bob is attracted in Bioinformatics recently. He reads papers day and night and devotes all his mind in studying. Today he is going to review the basic problem in Bioinformatics: DNA sequence alignment. His purpose is to find a simple and effective algorithm that performs global alignment with two highly similar DNA sequences. 

A DNA sequence is presented as a sequence of characters, which may be 'A', 'G','C' or 'T'. To align two DNA sequences, some gaps may be inserted to sequences so that two sequences have the same length. And then it is counted up for every pair of matched characters by a score matrix. Bob uses a minimal-score matrix hence the total score of alignment should be minimized. Following is the score matrix he uses: Õº∆¨ 1.png

  A G C T -
A 0 5 5 5 3
G 5 0 4 5 3
C 5 4 0 5 3
T 5 5 5 0 3
- 3 3 3 3 -
For example, an alignment for DNA sequences "AAGACG" and "CAGAGCTC" may be:
AAGA-  C- G 
CAGAGCTC 
The total score is 5+0+0+0+3+0+3+4=15. 

 ‰»Î
Input contains two lines, which are the two DNA sequences to align. DNA sequences contain only characters 'A', 'G', 'C' and 'T'. The length of each sequence is not greater than 1000.

 ‰≥ˆ
Output contains one integer which is the minimal total score of alignment.
*/
#include <stdio.h>
#include <string.h>
int min(int a, int b, int c)
{
	if(a <= b && a <= c)
		return a;
	else if( b > c)
		return c;
	else return b;
}
int score(char a, char b)
{
	if( a == b)
		return 0;
	if( a == 'A' || b == 'A' || a == 'T' || b == 'T')
		return 5;
	else return 4;
}
int main(void)
{
	int i, j;
	char string1[1024], string2[1024];
	scanf("%s", string1);
	scanf("%s", string2);
	int length1, length2;
	length1 = strlen(string1);
	length2 = strlen(string2);
	int opt[1024][1024];
	for(i = 0; i <= length1; i++)
		opt[i][0] = 3 * i;
	for(j = 0; j <= length2; j++)
		opt[0][j] = 3 * j;
	for(i = 1; i < length1 + 1; i++)
		for(j = 1; j < length2 + 1; j++)
			opt[i][j] = min(opt[i - 1][j - 1] + score(string1[i - 1], string2[j - 1]), opt[i - 1][j] + 3, opt[i][j - 1] + 3);
	printf("%d", opt[length1][length2]);
}