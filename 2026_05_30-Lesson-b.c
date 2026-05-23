#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isprint(int c)
{
	if( c>=' ' && c<='~' )
		return TRUE;
	else
		return FALSE;
}

int isgraph(int c)
{
	if( isprint(c) && c!=' ' )
		return TRUE;
	else
		return FALSE;
}

int main()
{
	char string[] = "Nothing beats knowing the ASCII codes!\n";
	char *s;

	/* output isgraph() test */
	puts("isgraph()");
	s = string;
	while( *s != '\0' )
	{
		putchar(*s);
		s++;
	}
	/* testing output */
	s = string;
	while( *s != '\0' )
	{
		if( isgraph(*s) )
			putchar('^');
		else
			putchar(' ');
		s++;
	}
	putchar('\n');

	/* output isprint() test */
	puts("isprint()");
	s = string;
	while( *s != '\0' )
	{
		putchar(*s);
		s++;
	}
	/* testing output */
	s = string;
	while( *s != '\0' )
	{
		if( isprint(*s) )
			putchar('^');
		else
			putchar(' ');
		s++;
	}
	putchar('\n');

	return 0;
}
