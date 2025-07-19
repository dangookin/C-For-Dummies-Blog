#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* rolling an 's' sided die */
int roll(int s)
{
	return( rand() % s + 1 );
}

int main()
{
	const int die = 6;
	/* d4, d6, d8, d12, d20, d100 */
	const int sides[] = {
		4, 6, 8, 12, 20, 100
	};
	int d[die];		/* six different die */
	int x;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* throw dem bones! */
	for( x=0; x<die; x++ )
		d[x] = roll( sides[x] );

	/* show results */
	printf("%5s%5s%5s%5s%5s%5s\n",
			"D4","D6","D8","D12","D20","D100"
		  );
	for( x=0; x<die; x++ )
		printf("%5d",d[x]);
	putchar('\n');

	return 0;
}
