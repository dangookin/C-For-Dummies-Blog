#include <stdio.h>

int main()
{
	double a;
	int r;

	r = _Generic( a, char: 1, int: 2, long: 3, default: 0 );
	printf("'a' is ");
	switch(r)
	{
		case 1:
			puts("a char");
			break;
		case 2:
			puts("an int");
			break;
		case 3:
			puts("a long");
			break;
		default:
			puts("unknown");
	}

	return(0);
}
