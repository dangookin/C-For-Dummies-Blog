#include <stdio.h>

int main()
{
	const int columns = 9;
	const int values = 100;
	int x,y,rows,count,v;

	x = 0;				/* track the rows */
	count = values;
	rows = values/columns+1;	/* how many rows are needed, max? */
	while( x<rows )
	{
		/* in stream output, columns alway appear first */
		for( y=0; y<columns; y++ )
		{
			/* calculate the value to output */
			v = x+(y*rows);			/* this value could also be
									   an array element number */
			if( v<values )			/* output only numbers in range */
			{
				printf("%3d",v);
				count--;				/* decrement the count */
				if( !count )			/* if count is zero, stop */
					break;
			}
			if( y<columns-1)			/* set tabs between numbers */
				putchar('\t');
		}
		x++;
		putchar('\n');
	}


	return(0);
}
