#include <stdio.h>

struct matrix {
	int *grid;
	int columns;
	int rows;
};

void output(char *title,struct matrix m)
{
	int x,y;

	puts(title);
	for( y=0; y<m.rows; y++ )
	{
		for( x=0; x<m.columns; x++ )
		{
			printf(" %3d ",*(m.grid+x+y*m.columns) );
		}
		putchar('\n');
	}
}

int main()
{
	int matrix_a[12] = {
		10, 20, 30, 40,
		11, 21, 31, 41,
		12, 22, 32, 42
	};
	int matrix_b[4] = {
		1, 2,
		3, 4
	};
	struct matrix a = { matrix_a, 4, 3 };
	struct matrix b = { matrix_b, 2, 2 };
	
	/* output each matrix */
	output("Matrix A",a);
	output("Matrix B",b);

	return 0;
}
