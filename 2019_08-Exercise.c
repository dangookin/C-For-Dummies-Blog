#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void fill_matrix(char m[])
{
	int x,r;

	for(x=0; x<SIZE*SIZE; x++)
	{
		r = rand() % 26;
		m[x] = 'a' + r;
	}
}

void show_matrix(char m[])
{
	int row,col;

	for(row=0; row<SIZE; row++)
	{
		for(col=0; col<SIZE; col++)
		{
			printf(" %c ",m[(row*SIZE)+col]);
		}
		putchar('\n');
	}
}

void rotate_matrix(char a[], char b[])
{
	int row_a,row_b,col_a,col_b;
	
	for(row_a=0,col_b=SIZE-1; row_a<SIZE; row_a++,col_b--)
	{
		for(col_a=0,row_b=0; col_a<SIZE; col_a++,row_b++)
		{
			b[(row_b*SIZE)+col_b] = a[(row_a*SIZE)+col_a];
		}
	}
}

int main()
{
	char matrix[SIZE*SIZE];
	char matrix_r[SIZE*SIZE];

	/* seed randomizer */
	srand( (unsigned)time(NULL) );
	
	fill_matrix(matrix);
	puts("Original:");
	show_matrix(matrix);
	rotate_matrix(matrix,matrix_r);
	puts("Rotated:");
	show_matrix(matrix_r);

	return(0);
}

