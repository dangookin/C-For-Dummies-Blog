#include <stdio.h>

#define mouse_enable() printf("\e[?1000h")
#define mouse_disable() printf("\e[?1000l")

int main()
{
	/* enable mouse reporting */
	mouse_enable();

	getchar();

	/* clean-up */
	mouse_disable();	/* disable mouse reporting */
	return 0;
}
