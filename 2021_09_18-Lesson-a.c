#include <stdio.h>

#define LENGTH 10

int main()
{
	char a = 'A';
	int x;

	for ( x=0; x<LENGTH; x++ )
		putchar(a++);
	putchar('\n');

	return(0);
}
