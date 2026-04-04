#include <stdio.h>

#define ROWS 16
#define COLUMNS 16
#define AREA ROWS*COLUMNS

int main()
{
	unsigned char grid[AREA];
	int x,y;
	
	for( y=0; y<ROWS; y++ )
	{
		for( x=0; x<COLUMNS; x++ )
		{
			grid[x] = x;
			printf("%02X ",x);
		}
		putchar('\n');
	}

	return 0;
}
