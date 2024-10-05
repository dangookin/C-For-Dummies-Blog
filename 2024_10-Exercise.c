#include <stdio.h>

struct matrix {
    int *grid;
    int rows;
    int columns;
};

void multiply(struct matrix a,struct matrix b)
{
	int r,c,x,v;

	for( r=0; r<a.rows; r++ )
	{
		for( c=0; c<b.columns; c++ )
		{
			v = 0;
			for( x=0; x<a.columns; x++ )
			{
				v+= *(a.grid+x+r*a.columns) * *(b.grid+x*b.columns+c);
			}
			printf("%4d ",v);
		}
		putchar('\n');
	}
}

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
    int matrix_a[16] = {
        10, 20, 30,
        11, 21, 31,
        12, 22, 32,
		13, 23, 33
    };
    int matrix_b[6] = {
        1, 2,
        3, 4,
		5, 6
    };
    struct matrix a = { matrix_a, 4, 3 };
    struct matrix b = { matrix_b, 3, 2 };

    /* output each matrix */
    output("Matrix A",a);
    output("Matrix B",b);

	/* multiple the matrixes */
	puts("Matrix A * Matrix B");
	multiply(a,b);

    return 0;
}
