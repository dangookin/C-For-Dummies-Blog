#include <stdio.h>

int main()
{
	char alphabet = 'A';

	while( alphabet!='Z'+1)
	{
		putchar(alphabet);
		putchar(alphabet+32);
		alphabet++;
	}
	putchar('\n');

	return(0);
}
