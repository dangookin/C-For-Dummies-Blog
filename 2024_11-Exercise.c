#include <stdio.h>

int main()
{
	int a,b,total;

	/* gather input */
	printf("First value: ");
	scanf("%d",&a);
	printf("Second value: ");
	scanf("%d",&b);

	/* do math */
	printf("Traditional: %d * %d = %d\n",a,b,a*b);
	printf("  Ethiopian: %d * %d = ",a,b);
	total = 0;
	while(a>0)
	{
		total += a%2 ? b : 0;
		a>>=1;
		b<<=1;
	}
	printf("%d\n",total);

	return 0;
}
