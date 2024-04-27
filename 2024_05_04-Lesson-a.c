#include <stdio.h>

int main()
{
	int ch = '\0';

	while(ch!=EOF)
	{
		ch = getchar();
		if( ch==' ' )
			printf("&nbsp;");
		else
			putchar(ch);
	}

	return(0);
}
