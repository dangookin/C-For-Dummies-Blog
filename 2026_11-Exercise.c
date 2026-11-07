#include <stdio.h>

void count(int n,int a)
{
	printf("%d\n",a);
	if( a==n )
		return;
	else
		count(n,a+1);
}

int main()
{
	int n;

	/* obtain input */
	printf("Loop count = ");
	scanf("%d",&n);

	/* test for bad input */
	if( n<1 )
	{
		puts("Enter a value larger than zero");
		return -1;
	}

	/* start at zero */
	count(n,1);
	
	return 0;
}
