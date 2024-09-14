#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

unsigned long long looksay(unsigned long long v)
{
	const int size = 128;
	char number[size],temp[size],*n,c;
	static char value[128];
	int count;
	unsigned long long r;

	/* convert and process the string */
	snprintf(number,size,"%lld",v);
	value[0] = '\0';		/* cap the buffer for strcat() */
	n = number;				/* initialize the pointer */
	while(*n)				/* loop through the string */
	{
		count = 0;			/* digit count */
		c = *n;				/* save the current digit */
		while( *n==c )		/* loop while the digits match */
		{
			count++;
			n++;
		}
		/* convert the result into a string */
		snprintf(temp,size,"%d%c",count,c);
		/* build the new value string */
		strcat(value,temp);
	}

	/* convert the string back into a long */
	r = strtoll(value,NULL,10);

	/* check for overflow */
	if( r==LONG_MAX )
	{
		puts("OVERFLOW");
		exit(1);
	}

	return(r);
}

int main()
{
	unsigned long long start;
	int x;

	printf("Starting value: ");
	scanf("%llu",&start);

	/* loop through 10 iterations */
	printf("%llu\n",start);
	for( x=0; x<10; x++ )
	{
		start = looksay(start);
		printf("%llu\n",start);
	}

	return 0;
}
