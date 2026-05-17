#include <stdio.h>
#include <ctype.h>

#define DEL 127

int main()
{
	int ch;

	for( ch=' '; ch<=DEL; ch++ )
	{
		printf("%3d %2X '%c' is",ch,ch,ch);
		if( isalnum(ch) )
		{
			printf(" alphanumeric");
			if( isalpha(ch) )
				printf(" (alphabetic)");
			if( isdigit(ch) )
				printf(" (digit)");
		}
		else
		{
			printf(" non-alphanumeric");
		}
		putchar('\n');
	}

	return 0;
}
