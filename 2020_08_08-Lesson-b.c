#include <stdio.h>

int main()
{
	switch( 4-2 )
	{
		case (4-0):
			puts("The answer is 4");
			break;
		case (4-1):
			puts("The answer is 3");
			break;
		case (4-2):
			puts("The answer is 2");
			break;
		case (4-3):
			puts("The answer is 1");
			break;
		case (4-4):
			puts("The answer is 0");
			break;
		default:
			puts("I don't know!");
	}

	return(0);
}
