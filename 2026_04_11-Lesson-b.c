#include <stdio.h>

#define ROWS 16
#define COLUMNS 16
#define AREA ROWS*COLUMNS
#define NORMAL "\e[m"

int main()
{
	unsigned char grid[AREA];
	int x,y;
	
	for( y=0; y<ROWS; y++ )
	{
		for( x=0; x<COLUMNS; x++ )
		{
			grid[x] = x;
			if( y<8 )
				printf("\e[3%cm%02X%s ",(x/4+1)+'0',x,NORMAL);
			else
				printf("\e[3%cm%02X%s ",(x/4+5)+'0',x,NORMAL);
		}
		putchar('\n');
	}

	return 0;
}
