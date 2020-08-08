#include <stdio.h>

int main()
{
	switch( 4-2 )
	{
		case 4:
			puts("The answer is 4");
			break;
		case 3:
			puts("The answer is 3");
			break;
		case 2:
			puts("The answer is 2");
			break;
		case 1:
			puts("The answer is 1");
			break;
		case 0:
			puts("The answer is 0");
			break;
		default:
			puts("I don't know!");
	}

	return(0);
}
