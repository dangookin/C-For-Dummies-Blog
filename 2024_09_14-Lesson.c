#include <stdio.h>

int main()
{
	const int size = 32;
	char number[size],*n,c;
	int start,count;

	/* fetch the starting value */
	printf("Value: ");
	scanf("%d",&start);

	/* convert `start` to a string */
	snprintf(number,size,"%d",start);

	/* process the string `number` */
	n = number;		/* initialize the pointer */
	while(*n)		/* loop through the string */
	{
		count = 0;				/* digit count */
		c = *n;					/* save the current digit */
		while( *n==c )			/* loop while the digits match */
		{
			count++;
			n++;
		}
		/* output the digit count and the digit */
		printf("%d%c",count,c);
	}
	putchar('\n');

	return 0;
}
