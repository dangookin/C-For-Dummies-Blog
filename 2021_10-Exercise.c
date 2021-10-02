#include <stdio.h>

int flip(char *c,int pos)
{
	(*(c+pos))++;					/* increment the letter */
	if( *(c+pos) > 'Z' )			/* check for overflow */
	{
		*(c+pos) = 'A';				/* reset back to a */
		if( pos!=0 )				/* watch for overflow */
		{
			if( !flip(c,pos-1) )	/* flip the next column's digit */
				return(0);			/* echo down the FALSE return */
		}
		else
			return(0);				/* last column, FALSE return */
	}
	return(1);						/* keep looping */
}

int main()
{
	const unsigned length = 4;
	char digits[length] = "AAAA";

	do
	{
		puts(digits);
	}
	while( flip(digits,length-1) );

	return(0);
}
