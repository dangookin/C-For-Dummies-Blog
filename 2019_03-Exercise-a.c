#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main()
{
	int array[SIZE];
	int a,b;

	/* initialize the randomizer and fill the array */
	puts("Array:");
	srand( (unsigned)time(NULL) );
	for(a=0;a<SIZE;a++)
	{
		array[a] = rand() % 50 + 10;
		printf(" %2d",array[a]);
	}
	putchar('\n');

	/* find and display duplicates */
	puts("Duplicates:");
	a = 0;
	while( a < SIZE-1 )
	{
		for(b=a+1;b<SIZE;b++)
		{
			if( array[a] == array[b] )
			{
				printf("%d\n",array[a]);
				/* no need to continue */
				break;
			}
		}
		a++;
	}

	return(0);
}
