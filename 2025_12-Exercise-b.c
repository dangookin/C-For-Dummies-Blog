#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int greatest(int a, int b, int c)
{
	return( b>a ? b>c ? b : c : a>c ? a : c );
}

int main()
{
	int x,y,z,g;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* generate three random values from 2 to 25 */
	x = rand() % 24 + 2;
	y = rand() % 24 + 2;
	z = rand() % 24 + 2;

	g = greatest(x,y,z);
	printf("The greatest of %d, %d, and %d is %d\n",
			x,y,z,g
		  );

	return 0;
}
