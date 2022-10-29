#include <stdio.h>

#define SIZE 8

int main()
{
	int square,row,column;

	for( square=0; square<SIZE*SIZE; square++ )
	{
		/* calculate row and column */
		column = square % SIZE;
		row = (square-column)/SIZE;
		printf("%d:%d ",row,column);
		if( column==SIZE-1 )
			putchar('\n');
	}

	return(0);
}
