#include <stdio.h>

int main()
{
	int a,b;

	a = 10;
	b = -10;

	switch( (int)(a > b)  )
	{
		case 1:
			printf("%d is greater than %d\n",a,b);
			break;
		case 0:
			printf("%d is not greater than %d\n",a,b);
			break;
		default:
			puts("I'm not sure what's going on");
	}

	return(0);
}
