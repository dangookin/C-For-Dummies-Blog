#include <stdio.h>

int main()
{
	int x,y;

	for( x='A',y='a'; x<='Z'; x++,y++ )
		printf("%c%c",x,y);
	putchar('\n');

	return(0);
}
