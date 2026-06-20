#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;

	puts("X Digits:");
	/* ASCII character range */
	for( ch=' '; ch<='~'; ch++ )
		if( isxdigit(ch) )
			putchar(ch);
	putchar('\n');

	return 0;
}
