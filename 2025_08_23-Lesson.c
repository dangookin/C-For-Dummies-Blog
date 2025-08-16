#include <stdio.h>
#include <math.h>
#include <time.h>

/* screen edges */
#define RIGHT_EDGE 78
#define LEFT_EDGE 2
/* movement delay in milliseconds */
#define PAUSE 50
/* values for e exponent */
#define TOP 25
#define BOTTOM 64
/* starting row */
#define ROW 20
/* larger momentum values = narrower arcs */
#define MOMENTUM 7
/* repeat count */
#define REPEAT 1013;

#define clear() printf("\e[H\e[2J")
#define cursor_off() printf("\e[?25l");
#define cursor_on() printf("\e[?25h");

/* move the cursor to position x (columns)
   and y (rows) and set character c */
void putat(x,y,c)
{
	printf("\e[%d;%dH%c",y,x,c);
}

/* pause for m milliseconds */
void delay(int m)
{
	long pause;
	clock_t now,then;

	pause = m*(CLOCKS_PER_SEC/1000);
	now = then = clock();
	while( (now-then) < pause )
		now = clock();
}

int main()
{
	int r,x,height,column,direction;
	char buffer[BUFSIZ];

	/* initialization */
	setvbuf(stdout,buffer,_IONBF,BUFSIZ);
	clear();
	cursor_off();
	column = 3;				/* starting column */
	direction = 1;			/* go right */
	r = REPEAT;				/* loop repeat count */

	while(r>0)
	{
		for( x=TOP; x<BOTTOM; x++ )
		{
			height = (int)exp( (double)x/ROW );
			if( x%MOMENTUM==0 )
			{
				column+=direction;
				if( column>RIGHT_EDGE || column<LEFT_EDGE )
					direction=-direction;
			}
			printf("\e[0;0H%04d",r--);
			putat( column, height, '*' );
			delay(PAUSE);
			putat( column, height, ' ' );
		}
		for( ; x>TOP; x-- )
		{
			height = (int)exp( (double)x/ROW );
			if( x%MOMENTUM==0 )
			{
				column+=direction;
				if( column>RIGHT_EDGE || column<LEFT_EDGE )
					direction=-direction;
			}
			printf("\e[0;0H%04d",r--);
			putat( column, height, '*' );
			delay(PAUSE);
			putat( column, height, ' ' );
		}
	}
	putat(LEFT_EDGE,ROW,'\n');
	cursor_on();

	return 0;
}
