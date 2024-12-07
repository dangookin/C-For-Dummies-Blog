#include <stdio.h>

int double_factorial(int a)
{
	if( a>2 )
		return( a * double_factorial(a-2) );
	return(a);
}

int main()
{
	int f;

	/* prompt */
	printf("Enter a positive integer: ");
	scanf("%d",&f);
	if( f<1 ) return -1;

	/* output results */
	printf("%d!! = %d\n",f,double_factorial(f) );

	return 0;
}
