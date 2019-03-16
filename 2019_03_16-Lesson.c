#include <stdio.h>
#include <stdlib.h>

#define SEPARATOR ';'
#define SEPARATOR ':'

int main()
{
	char *searchpath,*s;

	searchpath = getenv("PATH");
	s = searchpath;

	while(*s)
	{
		if( *s == SEPARATOR)
			putchar('\n');
		else
			putchar(*s);
		s++;
	}
	putchar('\n');

	return(0);
}

