#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* return TRUE for uppercase char */
int isupper(int c)
{
	if( c>='A' && c<='Z' )
		return TRUE;
	else
		return FALSE;
}

/* return TRUE for lowercase char */
int islower(int c)
{
	if( c>='a' && c<='z' )
		return TRUE;
	else
		return FALSE;
}

/* convert to uppercase */
int toupper(int c)
{
	if( islower(c) )
		c &= 0xDF;

	return(c);
}

/* convert to lowercase */
int tolower(int c)
{
	if( c>='A' && c<='Z' )
		c |= 0x20;

	return(c);
}

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
