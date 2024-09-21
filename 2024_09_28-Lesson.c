#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define home() printf("\e[H")
#define clear() printf("\e[H\e[2J")

/* set the cursor to position x (columns)
   and y (rows ) */
void locate(x,y)
{
	printf("\e[%d;%dH",y,x);
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
	int rows,columns;
	struct winsize w;
	char buffer[BUFSIZ];

	/* obtain the window size */
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	rows = w.ws_row;
	columns = w.ws_col;

	/* remove line buffering */
	setvbuf(stdout,buffer,_IONBF,BUFSIZ);

	/* position the asterisk */
	clear();
	locate(columns/2,rows/2);
	putchar('*');

	/* wait 1 second */
	delay(1000);
	/* home the cursor */
	home();

	return 0;
}
