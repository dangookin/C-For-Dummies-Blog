#include <stdio.h>

int main()
{
	int alpha = 5;

	switch(alpha)
	{
		case 1:
			puts("One");
		case 2:
			puts("Two");
		case 3:
			puts("Three");
		case 4:
			puts("Four");
		case 5:
			puts("Five");
		default:
			puts("Out of range");
	}

	return(0);
}

