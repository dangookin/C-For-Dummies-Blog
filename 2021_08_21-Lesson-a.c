#include <stdio.h>

void output(char a[])
{
	int x = 0;

	while( a[x] )
	{
		putchar( a[x]);
		x++;
	}
	putchar('\n');
}

int main()
{
	char string[] = "Hello, world!";

	output(string);

	return(0);
}
