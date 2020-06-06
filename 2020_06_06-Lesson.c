#include <stdio.h>
#include <stdlib.h>

char *ternary_out(unsigned n)
{
	static char tstring[11];
	int powers[12];
	int x;

	/* check for overflow */
	if( n<0 || n>65535 )
	{
		fprintf(stderr,"%d is out of range\n",n);
		exit(1);
	}

	/* create the 3 powers table */
	powers[0] = 1;
	for(x=1;x<12;x++)
	{
		powers[x] = powers[x-1]*3;
	}

	/* build the return string */
	tstring[0] = '\0';

	return(tstring);
}

int main()
{
	unsigned t;

	/* prompt for input */
	printf("Enter a value: ");
	scanf("%d",&t);

	printf("%d in ternary is %s\n",t,ternary_out(t));

	return(0);
}
