#include <stdio.h>

int main()
{
	int a;

	for(a=1;a<=100;a++)
	{
		if( a % 3 == 0 )
			printf("Fizz");
		if( a % 5 == 0 )
			printf("Buzz");
		if( a%3 && a%5 )
			printf("%d",a);
		putchar('\n');
	}

	return(0);
}
		
