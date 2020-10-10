#include <stdio.h>

unsigned cumulative(unsigned n)
{
	while(n)
		return(n + cumulative(n-1));
	return(n);
}

int main()
{
	unsigned v;

	printf("Type a positive integer value: ");
	scanf("%u",&v);

	printf("The total of all numbers 1 through %u is %u\n",
			v,
			cumulative(v)
		  );

	return(0);
}
