#include <stdio.h>

/* convert to uppercase */
int toupper(int c)
{
	if( c>='a' && c<='z' )
		c -= 32;

	return(c);
}

/* convert to lowercase */
int tolower(int c)
{
	if( c>='A' && c<='Z' )
		c += 32;

	return(c);
}

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
