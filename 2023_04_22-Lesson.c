#include <stdio.h>

/* assumptions */
#define TAB_STOP 8
#define LINE_LEN 80

int main()
{
	int ch,offset,spaces,x;

	offset = 0;
	while(1)
	{
		ch = getchar();
		if( ch==EOF )
			break;
		switch(ch)
		{
			case ' ':
				printf("&nbsp;");
				offset++;
				break;
			case '&':
				printf("&amp;");
				offset++;
				break;
			case '<':
				printf("&lt;");
				offset++;
				break;
			case '>':
				printf("&gt;");
				offset++;
				break;
			case '\t':
				spaces = TAB_STOP-(offset%TAB_STOP);
				for( x=0; x<spaces; x++ )
				{
					offset++;
					printf("&nbsp;");
				}
				break;
			case '\n':
			case '\r':
				putchar(ch);
				offset = 0;
				break;
			default:
				putchar(ch);
				offset++;
		}
		if( offset==LINE_LEN )
			offset = 0;
	}

	return(0);
}
