#include <stdio.h>
#include <unistd.h>

int main()
{
	int x;

	printf("Prompt: ");
	printf("\e7");		/* save cursor position */

	/* output 20 Xs */
	for(x=0;x<20;x++)
		putchar('X');
	fflush(stdout);

	/* wait */
	sleep(1);

	/* output 20 Zs */
	printf("\e8");		/* restore cursor position */
	for(x=0;x<20;x++)
		putchar('Z');
	putchar('\n');

	return 0;
}
