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
	int color;

	color = x/10;
	switch(color)
	{
		case 0:			/* red */
			printf("\e[31m\e[%d;%dH%c",y,x,c);
			break;
		case 1:			/* green */
			printf("\e[32m\e[%d;%dH%c",y,x,c);
			break;
		case 2:			/* yellow */
			printf("\e[33m\e[%d;%dH%c",y,x,c);
			break;
		case 3:			/* blue */
			printf("\e[34m\e[%d;%dH%c",y,x,c);
			break;
		case 4:			/* magenta */
			printf("\e[35m\e[%d;%dH%c",y,x,c);
			break;
		case 5:			/* cyan */
			printf("\e[36m\e[%d;%dH%c",y,x,c);
			break;
		default:
			printf("\e[37m\e[%d;%dH%c",y,x,c);
	}
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
	int rows,columns,vert,horz,a;
	const int length = 7;
	struct winsize w;
	struct coord {
		int y;
		int x;
	} tail[length];
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
	vert=1;
	horz=1;
	for( a=0; a<length; a++ )
	{
		tail[a].y = columns/2;
		tail[a].x = rows/2;
	}

	/* bounce the asterisk */
	while(1)
	{
		/* end the loop on key press */
		if( kbhit() )
		{
			getchar();
			break;
		}
		/* output the snake */
		putat( tail[0].y, tail[0].x, ' ');	/* erase the tail */
		for( a=1; a<length; a++ )
			putat( tail[a].y, tail[a].x, '*');
		/* update the snake */
		for( a=0; a<length-1; a++ )
		{
			tail[a].y = tail[a+1].y;
			tail[a].x = tail[a+1].x;
		}
		/* move the head */
		tail[length-1].x += horz;
		tail[length-1].y += vert;
		delay(125);				/* 1/8 sec. delay */
		/* check bounds */
		if( tail[length-1].y==columns-1 || tail[length-1].y==1 )
			vert=-vert;			/* switch directions */
		if( tail[length-1].x==rows-1 || tail[length-1].x==2 )
			horz=-horz;			/* switch directions */
	}
	/* set the cursor and say goodbye */
	putat(1,rows-1,'B');
	puts("ye!");

	return 0;
}
