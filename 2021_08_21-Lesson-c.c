#include <stdio.h>

void output(char *a)
{
	int x = 0;

	while( *(a+x) )
	{
		putchar(*(a+x));
		x++;
	}
	putchar('\n');
}

int main()
{
	char *string[3] = {
		"Hello, world!",
		"This is a string test",
		"Once upon a time, there was a string"
	};
	int x;

	for( x=0; x<3; x++ )
	{
		output(string[x]);
	}

	return(0);
}
