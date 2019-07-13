#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int convert(char *s)
{
	int len,x,r;

	len = strlen(s);
	for( x=0, r=0; x<len; x++ )
	{
		r += ( *(s+len-x-1) - '0' ) * pow( 10.0, (double)x );
	}

	return(r);
}

int main()
{
	char value[] = "345966";
	int v;

	v = atoi(value);
	printf("%s from atoi() is %d\n",value,v);
	v = convert(value);
	printf("%s from convert() is %d\n",value,v);

	return(0);
}
