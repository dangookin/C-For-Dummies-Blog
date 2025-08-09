#include <stdio.h>
#include <math.h>
#include <time.h>

#define clear() printf("\e[H\e[2J")

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
	int x;
	double b;
	char buffer[BUFSIZ];

	/* initialization */
	setvbuf(stdout,buffer,_IONBF,BUFSIZ);
	clear();

	for( x=5; x<64; x++ )
	{
		b=exp( (double)x/20 );
		putat( 3, (int)b, '*' );
		delay(50);
		putat( 3, (int)b, ' ' );
	}
	putchar('\n');

	return 0;
}
