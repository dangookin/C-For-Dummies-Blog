#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>

#define clear() printf("\e[H\e[2J")
#define moveto(a,b) printf("\e[%d;%dH",b,a)
#define mouse_enable() printf("\e[?1000h")
#define mouse_motion() printf("\e[?1003h")
#define mouse_extended() printf("\e[?1006h")
#define mouse_disable() printf("\e[?1000l")

struct mouse_data {
	int button;
	int column;
	int row;
};

/* read an integer from a string
   Exercise 2026_02 */
char *extract(char *s)
{
	static char *sp;

	/* check for recall */
	if( s != NULL )
		sp = s;
	else
		while( isdigit(*sp) )
			sp++;

	/* find the next digit */
	while( *sp != '\0' )
	{
		if( isdigit(*sp) )
		{
			return(sp);
		}
		sp++;
	}

	return(NULL);
}

/* obtain values from mouse data */
void read_mouse(char *b, struct mouse_data *m)
{
	m->button = atoi(extract(b));
	m->column = atoi(extract(NULL));
	m->row = atoi(extract(NULL));
}

int main()
{
	struct termios original,noecho;
	struct mouse_data mickey;
	char buffer[13];
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
	clear();
	puts("Play with the mouse; press Enter  to end");
	while( (key=getchar()) != '\n' )
	{
		read(fileno(stdin),buffer,12);
		buffer[12] = '\0';		/* make it a string */
		read_mouse(buffer,&mickey);
		if( mickey.button != 35 )
		{
			clear();
			moveto(mickey.column,mickey.row);
			printf("%d",mickey.button);
			moveto(1,1);
			printf("Button %d clicked at column %d row %d\n",
					mickey.button,
					mickey.column,
					mickey.row
				  );
		}
		else	
		{
			clear();
			printf("Mouse moving to column %d row %d\n",
					mickey.column,
					mickey.row
				  );
		}
	}

	/* clean-up */
	mouse_disable();	/* disable mouse reporting */
	tcsetattr(fileno(stdin), TCSANOW, &original);
	return 0;
}
