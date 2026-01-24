#include <stdio.h>

#define mouse_enable() printf("\e[?1000h")
#define mouse_motion() printf("\e[?1003h")
#define mouse_extended() printf("\e[?1006h")
#define mouse_disable() printf("\e[?1000l")

int main()
{
	/* enable mouse reporting */
	mouse_enable();
	mouse_motion();
	mouse_extended();

	getchar();

	/* clean-up */
	mouse_disable();	/* disable mouse reporting */
	return 0;
}
