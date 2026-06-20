#include <stdio.h>
#include <stdbool.h>

int isxdigit(int c)
{
	if( c>='0' && c<='9' )
		return true;
	if( c>='A' && c<='F' )
		return true;
	if( c>='a' && c<='f' )
		return true;

	return false;
}

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
