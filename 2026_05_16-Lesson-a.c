#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Nothing beats knowing the ASCII codes!\n";
	char *s;

	/* output normal */
	printf("%s",string);

	/* invert case */
	s = string;
	while( *s != '\0' )
	{
		if( islower(*s) )
			putchar( toupper(*s) );
		else if( isupper(*s) )
			putchar( tolower(*s) );
		else
			putchar(*s);
		s++;
	}

	return 0;
}
