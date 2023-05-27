#include <stdio.h>

int main()
{
	int a,b;

	printf("Enter value A: ");
	scanf("%d",&a);
	printf("Enter value B: ");
	scanf("%d",&b);

	printf("Before: A=%d, B=%d\n",a,b);

	/* swap variables */
	b = b + a;
	a = b - a;
	b = b - a;

	printf("After: A=%d, B=%d\n",a,b);

	return(0);
}
