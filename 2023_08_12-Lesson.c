#include <stdio.h>
#include <stdlib.h>
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
	char *v[count];
	int x,c;
	char *n;

	for(x=0; x<count; x++ )
	{
		n = variable[x];		/* initialize pointer n */
		c = 0;					/* initialize offset */

		/* test for the underscore */
		if( strchr(variable[x],'_') )
		{
			/* name is in snake_case */
			/* camelCase will be shorter, so just allocate
			   the same storage */
			v[x] = malloc( strlen(variable[x]) + 1 );
			/* error checking goes here */
			while( *n )
			{
				if( *n=='_' )
				{
					n++;
					*(v[x]+c) = toupper(*n);
				}
				else
				{
					*(v[x]+c) = *n;
				}
				n++;
				c++;
			}
		}
		else
		{
			/* name is in camelCase */
			/* allocate storage for worst case */
			v[x] = malloc( strlen(variable[x]) * 2 + 1 );
			/* error checking goes here */
			while( *n )
			{
				if( isupper(*n) )
				{
					*(v[x]+c) = '_';
					c++;
					*(v[x]+c) = tolower(*n);
				}
				else
				{
					*(v[x]+c) = *n;
				}
				n++;
				c++;
			}
		}
		/* cap the string */
		*(v[x]+c) = '\0';
	}

	/* output the result */
	for(x=0; x<count; x++ )
		printf("%25s -> %s\n",
				variable[x],
				v[x]
			  );

	return(0);
}
