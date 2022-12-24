#include <stdio.h>
#include <stdlib.h>

/* return a string of character c
   length len */
char *chrstr(char c, int len)
{
	char *s;
	int x;

	/* quick test for null or bad arguments */
	if( c=='\0' || len<=0 )
		return(NULL);		/* return NULL on error */

	/* allocate storage */
	s = malloc( len * sizeof(char) + 1 );	/* +1 for the null char */
	/* test for memory error */
	if( s==NULL )			/* return NULL on error */
		return(s);

	/* fill the string */
	for( x=0; x<len; x++ )
		*(s+x) = c;
	
	/* cap the string */
	*(s+x) = '\0';

	return(s);
}

int main()
{
	int x,stars;
	const int height = 20;	/* 20 rows tall */

	for( x=0,stars=1 ; x<height; x++,stars+=2 )
	{
		/* print the indent */
		printf("%s%s\n",
				chrstr(' ',height-x),
				chrstr('*',stars)
			  );
	}

	return(0);
}
