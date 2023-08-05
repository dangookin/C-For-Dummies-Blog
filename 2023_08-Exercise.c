#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	const int count = 7;
	char *variable[] = {
		"readInputMeter",
		"cyclical_redundancy_check",
		"bumpyRide",
		"search_for_node",
		"string_convert",
		"divideByZeroError",
		"giveUpAndExplode"
	};
	int x;
	char *n;

	for(x=0; x<count; x++ )
	{
		printf("%25s -> ",variable[x]);
		n = variable[x];		/* initialize pointer n */

		/* test for the underscore */
		if( strchr(variable[x],'_') )
		{
			/* name is in snake_case */
			while( *n )
			{
				if( *n=='_' )
				{
					n++;
					/* test for overflow */
					if( *n=='\0' ) break;
					putchar( toupper(*n) );
				}
				else
				{
					putchar(*n);
				}
				n++;
			}
		}
		else
		{
			/* name is in camelCase */
			while( *n )
			{
				if( isupper(*n) )
				{
					putchar('_');
					putchar( tolower(*n) );
				}
				else
				{
					putchar(*n);
				}
				n++;
			}
		}
		putchar('\n');
	}

	return(0);
}
