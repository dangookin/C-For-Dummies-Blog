#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Hello there, strange... little planet\n";
	int x,y;

	x = 0;
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
				y = 1;
				while(string[x+y])
				{
					if( !isalpha(string[x+y]) )
						y++;
					else
						break;
				}
				x+=y;
			default:
				putchar( string[x] );
		}
		x++;
	}

	return(0);
}

