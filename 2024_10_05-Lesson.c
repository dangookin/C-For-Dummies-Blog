#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define home() printf("\e[H")
#define clear() printf("\e[H\e[2J")

/* check for a key waiting */
int kbhit(void)
{
	int k;

	ioctl(STDIN_FILENO,FIONREAD,&k);

	return(k);
}

/* set the cursor to position x (columns)
   and y (rows ) and set character c */
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

/* set an asterisk in the center of the screen */
int main()
{
	int rows,columns,posx,posy,vert,horz;
	struct winsize w;
	char buffer[BUFSIZ];

	/* obtain the window size */
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	rows = w.ws_row;
	columns = w.ws_col;

	/* remove line buffering */
	setvbuf(stdout,buffer,_IONBF,BUFSIZ);

	/* initialize */
	clear();
	puts("Press Enter to end");
	posx=columns/2;
	posy=rows/2;
	vert=1;
	horz=1;

	/* bounce the asterisk */
	while(1)
	{
		/* end the loop on key press */
		if( kbhit() )
		{
			getchar();
			break;
		}
		/* position the cursor */
		putat(posx,posy,'*');
		delay(125);				/* 1/8 sec. delay */
		putat(posx,posy,' ');	/* erase */
		/* check bounds */
		if( posx==columns-1 || posx==1 )
			horz=-horz;			/* switch directions */
		posx += horz;
		if( posy==rows-1 || posy==2 )
			vert=-vert;			/* switch directions */
		posy += vert;
	}
	/* set the cursor and say goodbye */
	putat(1,rows-1,'B');
	puts("ye!");

	return 0;
}
