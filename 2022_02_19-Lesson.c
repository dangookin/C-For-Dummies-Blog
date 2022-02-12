#include <stdio.h>

int main()
{
	int a = 10;

	printf("Variable a = %d\n",a);
	{
		int b = a+5;
		printf("Variable b = %d\n",b);
		int c = b+a;
		printf("Variable c = %d\n",c);
	}
	int d = a+b/c;
	printf("Variable d = %d\n",d);

	return(0);
}
