#include <stdio.h>

int main()
{
	const int columns = 9;
	const int values = 100;
	int x,y,count;

	x = 0;
	count = values;
	while( count )
	{
		for( y=0; y<columns; y++ )
		{
			printf("%3d",(x*columns)+y );
			count--;				/* decrement the count */
			if( !count )			/* if count is zero, stop */
				break;
			if( y<columns-1)
				putchar('\t');
		}
		x++;
		putchar('\n');
	}


	return(0);
}
