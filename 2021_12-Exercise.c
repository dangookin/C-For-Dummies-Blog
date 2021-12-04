#include <stdio.h>

int main()
{
	int current,previous;

	/* process input */
	previous = 0;
	while( (current=getchar()) != EOF )
	{
		printf("%02X",(unsigned char)(current-previous));
		previous = current;
	}
	putchar('\n');

	return(0);
}
