#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int compare(const void *a, const void *b)
{
	return( *(int *)a - *(int *)b );
}

int main()
{
	int array[SIZE];
	int a,b,d;

	/* initialize the randomizer and fill the array */
	puts("Array:");
	srand( (unsigned)time(NULL) );
	for(a=0;a<SIZE;a++)
	{
		array[a] = rand() % 50 + 10;
		printf(" %2d",array[a]);
	}
	putchar('\n');

	/* sort and display duplicates */
	qsort(array,SIZE,sizeof(int),compare);
	puts("Duplicates:");
	for(a=0;a<SIZE-1;a++)
	{
		b = 1;
		while( array[a] == array[a+b] )
		{
			d = array[a];
			b++;
			a++;
			/* prevent overflow */
			if( a + b > SIZE)
				break;
		}
		/* b is >1 only for duplicates */
		if( b > 1 )
			printf("%d\n",d);
	}

	return(0);
}
