#include <stdio.h>

int main()
{
	int alpha = 5;

	switch(alpha)
	{
		case 1:
			puts("One");
			break;
		case 2:
			puts("Two");
			break;
		case 3:
			puts("Three");
			break;
		case 4:
			puts("Four");
			break;
		case 5:
			puts("Five");
			break;
		default:
			puts("Out of range");
	}

	return(0);
}

