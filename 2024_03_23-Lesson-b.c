#include <stdio.h>

int main()
{
	char a;

	a = 'A';
	while(1)
	{
		printf(" %c",a++);
		if( a=='Z' )
			a = 'A';
		/* terminate on key */
		if(getchar())
			break;
	}

	return 0;
}
