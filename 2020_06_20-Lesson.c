#include <stdio.h>
#include <stdlib.h>

unsigned ternary_in(char *t)
{
	int powers[11];
	int len,x,r,p;

	/* create the 3 powers table */
	powers[0] = 1;
	for(x=1;x<11;x++)
	{
		powers[x] = powers[x-1]*3;
	}

	/* translate the string */
		/* find the end of the string */
	len = 0;
	while(1)
	{
		if( *(t+len)=='\n' || *(t+len)=='\0' )
		{
			break;
		}
		len++;
		/* limit to 11 digits */
		if( len==11 )
			break;
	}
	/* backup over the null character */
	len--;

	/* process the string backward
	   but process the powers table forward */
	r = 0;
	for( x=len,p=0 ; x>=0 ; x--,p++)
	{
		/* bail on invalid digit */
		if( *(t+x)<'0' || *(t+x)>'2' )
			return(-1);
		r += ( (*(t+x)-'0') * powers[p] );
	}

	return(r);
}

int main()
{
	char input[12];
	int ternary;

	/* prompt for input */
	printf("Enter a value in ternary: ");
	fgets(input,12,stdin);

	ternary = ternary_in(input);
	if( ternary==-1 )
		puts("Invalid input");
	else
		printf("This value is %d decimal\n",ternary_in(input));

	return(0);
}
