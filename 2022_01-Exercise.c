#include <stdio.h>

/* return a hex digit integer value or
   -1 for an invalid character */
int hexdigit(char c)
{
	if( c>='A' && c<='F' )
		return( c - 'A' + 10);
	else if( c>='0' && c<='9' )
		return(c - '0');
	else
		return(-1);
}

int main()
{
	int ch,a,b,byte;

	/* process input */
	byte = 0;
	while(1)
	{
		/* obtain first hex digit */
		ch = getchar();
		if( ch==EOF ) break;
		a = hexdigit(ch);
		if( a<0 ) break;

		/* obtain second hex digit */
		ch = getchar();
		if( ch==EOF ) break;
		b = hexdigit(ch);
		if( b<0 ) break;

		/* build a byte using the current hex
		   digit plus the previous digit in
		   byte */
		byte += (a<<4) + b;
		putchar(byte);
	}

	return(0);
}
