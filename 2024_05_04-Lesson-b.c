#include <stdio.h>

int main()
{
	int ch;

	while( (ch=getchar()) != EOF )
	{
		if( ch==' ' )
			printf("&nbsp;");
		else
			putchar(ch);
	}

	return(0);
}
