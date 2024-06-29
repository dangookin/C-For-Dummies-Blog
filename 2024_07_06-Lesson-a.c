#include <stdio.h>
#include <unistd.h>

int main()
{
	int x;

	for(x=0;x<20;x++)
		putchar('X');
	fflush(stdout);
	sleep(1);
	for(x=0;x<20;x++)
		putchar('\b');
	putchar('\n');

	return 0;
}
