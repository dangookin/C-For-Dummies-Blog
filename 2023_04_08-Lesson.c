#include <stdio.h>

int main()
{
	int ch;

	while(1)
	{
		ch = getchar();
		if( ch==EOF )
			break;
		switch(ch)
		{
			case ' ':
				printf("&nbsp;");
				break;
			case '\t':
				printf("&nbsp;&nbsp;&nbsp;&nbsp;");
				break;
			default:
				putchar(ch);
		}
	}

	return(0);
}
