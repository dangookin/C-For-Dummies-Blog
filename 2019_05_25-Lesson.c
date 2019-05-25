#include <stdio.h>

int main()
{
	char string[] = "Hello there strange little planet\n";
	int x = 0;

	while( string[x] )
	{
		switch( string[x] )
		{
			case ' ':
			case '.':
			case ',':
			case '!':
			case '?':
			case ';':
			case ':':
			case '\n':
				putchar('\n');
				break;
			default:
				putchar( string[x] );
		}
		x++;
	}

	return(0);
}

