#include <stdio.h>
#include <stdlib.h>

#define BASE 5
 
/* translate value to string */
char *base_out(unsigned n)
{
	static char tstring[12];
	char *t;
	int powers[12];
	int x,r;

	/* check for overflow */
	if( n<0 || n>65535 )
	{
		fprintf(stderr,"%d is out of range\n",n);
		exit(1);
	}

	/* create the powers table */
	powers[0] = 1;
	for(x=1;x<12;x++)
	{
		powers[x] = powers[x-1]*BASE;
	}

	/* build the return string */
	tstring[11] = '\0';
	for(x=0;x<11;x++)
	{
		r = n % powers[x+1];
		n -= r;
		tstring[10-x] = r/powers[x] + '0';
	}

	/* remove any leading zeros */
	t = tstring;
	x = 0;
	while( *t=='0' && x<10 )
	{
		t++;
		x++;
	}

	return(t);
}

/* translate string to value */
unsigned base_in(char *t)
{
	int powers[11];
	int len,x,r,p;

	/* create the powers table */
	powers[0] = 1;
	for(x=1;x<11;x++)
	{
		powers[x] = powers[x-1]*BASE;
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
		if( *(t+x)<'0' || *(t+x)>(BASE+'0') )
			return(-1);
		r += ( (*(t+x)-'0') * powers[p] );
	}

	return(r);
}

int main()
{
	unsigned b;
	char *bstring;

	printf("Base %d I/O\n",BASE);
	/* prompt for input */
	printf("Enter a decimal value: ");
	scanf("%d",&b);

	bstring = base_out(b);
	printf("%d in base %d is %s\n",b,BASE,bstring);
	printf("%s in decimal is %d\n",bstring,base_in(bstring));

	return(0);
}
