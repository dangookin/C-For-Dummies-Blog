#include <stdio.h>

int main()
{
	const int size = 12;
	long power[size];
	int base,value,x,r,pre;

	/* prompt for input */
	printf("Enter base (>1 <11): ");
	scanf("%d",&base);
	if( base<2 || base>10 )
	{
		puts("The base must be greater than 1 and less than 11");
		return 1;
	}
	printf("Enter value (>1): ");
	scanf("%d",&value);
	if( value<2 )
	{
		puts("The value must be greater than 1");
		return 1;
	}

	/* build the powers table */
	for( x=0; x<size; x++ )
		/* calculate powers; power 0 is always 1 */
		power[x] = x ? power[x-1]*base : 1;

	/* output the value in the given base */
	printf("%d in base %d is ",value,base);
	pre = 0;
	for( x=size-2; x>=0; x-- )
	{
		/* process digits from largest to smallest */
		r = (value % power[x+1])/power[x];
		if( r==0 && pre==0 )	/* skip over leading zeros */
			continue;
		else
		{
			pre = 1;			/* no more leading zeros */
			printf("%d",r);
		}
	}
	putchar('\n');

	return 0;
}
