#include <stdio.h>

int main()
{
	int x;

	for( x='A'; x<='Z'; x++ )
		printf("%c%c",x,x+32);
	putchar('\n');

	return(0);
}
