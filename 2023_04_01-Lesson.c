#include <stdio.h>

int main()
{
	int ch;

	while(1)
	{
		ch = getchar();
		if( ch==EOF )
			break;
		if( ch==' ' )
			printf("&nbsp;");
		else
			putchar(ch);
	}

	return(0);
}
