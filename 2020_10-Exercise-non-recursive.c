#include <stdio.h>

unsigned cumulative(unsigned n)
{
	unsigned a,total;

	total = 0;
	for(a=1; a<=n; a++)
	{
		total=total+a;
	}

	return(total);
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
