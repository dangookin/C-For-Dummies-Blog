#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define mouse_enable() printf("\e[?1000h")
#define mouse_extended() printf("\e[?1006h")
#define mouse_motion() printf("\e[?1003h")
#define mouse_disable() printf("\e[?1000l")

int main()
{
	struct termios original,noecho;
	char buffer[12];
	int key;

	/* obtain terminal configuration */
	tcgetattr(fileno(stdin),&original);
	noecho = original;		/* duplicate */
		/* enable raw input */ 
	noecho.c_lflag = noecho.c_lflag ^ ICANON;
		/* disable full duplex */
	noecho.c_lflag = noecho.c_lflag ^ ECHO;
		/* update terminal definition */
	tcsetattr(fileno(stdin), TCSANOW, &noecho);

	/* enable mouse reporting */
	mouse_enable();
	mouse_motion();
	mouse_extended();
	/* remove line buffering */
	setvbuf(stdin,NULL,_IONBF,0);

	/* read stdin */
	puts("Play with the mouse; press Enter to end");
	while( (key=getchar()) != '\n' )
	{
		read(fileno(stdin),buffer,12);
		write(fileno(stdout),buffer,12);
		putchar('\n');
	}

	/* clean-up */
	mouse_disable();	/* disable mouse reporting */
	tcsetattr(fileno(stdin), TCSANOW, &original);
	return 0;
}
