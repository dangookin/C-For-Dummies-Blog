#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 17
#define COLUMNS 17
#define AREA ROWS*COLUMNS

int main()
{
	unsigned char grid[AREA];
	int x,y,min,max;
	unsigned long total,average;
	
	/* seed randomizer */
	srand( (unsigned)time(NULL) );

	max = 0;
	min = 255;
	total = 0;
	for( x=0; x<AREA; x++ )
	{
		grid[x] = rand()%256;	/* range is 0 through 255 */
		max = grid[x]>max ? grid[x] : max;
		min = grid[x]<min ? grid[x] : min;
		total += grid[x];
	}

	for( y=0; y<ROWS; y++ )
	{
		for( x=0; x<COLUMNS; x++ )
			printf("%02X ",grid[ y*COLUMNS + x ]);
		putchar('\n');
	}
	printf("min = %d\nmax=%d\n",min,max);
	printf("total is %ld\n",total);
	average = total/(AREA);
	printf("average is %lu/%d = %lu\n",total,AREA,average);

	return 0;
}
