#include <stdio.h>

#define ROWS 16
#define COLUMNS 16
#define AREA ROWS*COLUMNS
#define NORMAL "\e[m"

int main()
{
	unsigned char grid[AREA];
	int x,y,v,h,row,col;
	int chunk_horz,chunk_vert,grid_width,grid_height;
	int total;
	
	for( y=0; y<ROWS; y++ )
	{
		for( x=0; x<COLUMNS; x++ )
		{
			grid[y*COLUMNS+x] = (y*COLUMNS)+x;
			if( y<ROWS/2 )
				printf("\e[3%cm%02X%s ",
						(x/4+1)+'0',
						grid[y*COLUMNS+x],
						NORMAL
					  );
			else
				printf("\e[4%c;30m%02X%s ",
						(x/4+1)+'0',
						grid[y*COLUMNS+x],
						NORMAL
					  );
		}
		putchar('\n');
	}

	/* split into chunks */
	chunk_horz = 4;
	chunk_vert = 8;
	grid_height = ROWS/chunk_vert;
	grid_width = COLUMNS/chunk_horz;

	/* part out the chunks */
	for( y=0; y<grid_height; y++ )
	{
		for( x=0; x<grid_width; x++ )
		{
			total = 0;
			printf("Chunk %d:%d",y,x);
			for( v=0; v<chunk_vert; v++ )
			{
				for( h=0; h<chunk_horz; h++ )
				{
					row = y*chunk_vert+v;
					col = x*chunk_horz+h;
					total += grid[row*COLUMNS+col];
				}
			}
			printf(" average = %2X\n",total/(chunk_vert*chunk_horz));
		}
	}

	return 0;
}
