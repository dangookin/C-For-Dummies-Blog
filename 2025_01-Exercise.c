/*
   Exercise January 2025
   emulate the % operator
*/
#include <stdio.h>

int mod(int x, int y)
{
	return( x-y * (x/y) );
}

int main()
{
	int a,b;

	printf("Enter two integers separated by a space: ");
	scanf("%d",&a);
	scanf("%d",&b);

	printf("%% operator: %d %% %d = %d\n", a, b, a%b);
	printf("mod() function: %d %% %d = %d\n", a, b, mod(a,b));

	return 0;
}
