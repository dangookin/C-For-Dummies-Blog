#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Nothing beats knowing the ASCII codes!\n";
	char *s;

	/* uppercase */
	s = string;
	while( *s != '\0' )
	{
		putchar( toupper(*s) );
		s++;
	}

	/* lowercase */
	s = string;
	while( *s != '\0' )
	{
		putchar( tolower(*s) );
		s++;
	}

	return 0;
}
