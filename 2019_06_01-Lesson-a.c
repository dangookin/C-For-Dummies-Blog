#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Hello there, strange... little planet\n";
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
				if( string[x+1] == '\0' )
					break;
				if( !isalpha(string[x+1]) )
					x++;
				break;
			default:
				putchar( string[x] );
		}
		x++;
	}

	return(0);
}

