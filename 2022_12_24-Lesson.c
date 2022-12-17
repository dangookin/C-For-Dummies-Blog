#include <stdio.h>

int main()
{
	int x,y,stars;
	const int height = 20;	/* 20 rows tall */

	for( x=0,stars=1 ; x<height; x++,stars+=2 )
	{
		/* print the indent */
		printf("%*c",height-x,' ');
		for( y=0; y<stars; y++ )
		{
			putchar('*');	
		}
		putchar('\n');
	}

	return(0);
}
