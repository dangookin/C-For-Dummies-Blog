#include <stdio.h>
#include <unistd.h>

#define mouse_enable() printf("\e[?1000h")
#define mouse_extended() printf("\e[?1006h")
#define mouse_disable() printf("\e[?1000l")

int main()
{
	char buffer[12];
	int key;

	/* enable mouse reporting */
	mouse_enable();
	mouse_extended();
	/* remove line buffering */
	setvbuf(stdin,NULL,_IONBF,0);

	/* read stdin */
	puts("Click the mouse; press Enter to end");
	while( (key=getchar()) != '\n' )
	{
		read(fileno(stdin),buffer,12);
		write(fileno(stdout),buffer,12);
	}

	/* clean-up */
	mouse_disable();	/* disable mouse reporting */
	return 0;
}
