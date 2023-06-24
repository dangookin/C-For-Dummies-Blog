#include <stdio.h>

int sum(int a)
{
	char num[32];
	int x,t;

	snprintf(num,32,"%d",a);
	for( x=0, t=0; num[x]; x++ )
		t+=num[x]-'0';

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
