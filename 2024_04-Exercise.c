#include <stdio.h>

int main()
{
	int a;

	printf("Enter an integer: ");
	scanf("%d",&a);

	if( a<0 )
		a = -a;

	printf("The absolute value is %d\n",a);

	return 0;
}
