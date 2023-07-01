#include <stdio.h>

int sum(int a)
{
	int t;

	for( t=0; a; a/=10 )
		t+= a % 10;

	return(t);
}

int main()
{
	int d,t;

	/* beg for input */
	printf("Enter a positive integer: ");
	scanf("%d",&d);

	/* sum the digits */
	t = sum(d);
	printf("The sum of the digits is %d\n",t);

	return(0);
}
