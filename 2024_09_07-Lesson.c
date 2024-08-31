#include <stdio.h>

void remove_element(int array[], int size, int element)
{
	int x;

	for( x=element; x<size-1; x++ )
		array[x] = array[x+1];
	array[x] = 0;
}

int main()
{
	int alpha[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int x;

	puts("Original array:");
	for(x=0; x<10; x++)
	   printf("%2d ",alpha[x]);
	putchar('\n');

	remove_element(alpha,10,4);

	puts("After removing the 5th element:");
	for(x=0; x<10; x++)
	   printf("%2d ",alpha[x]);
	putchar('\n');

	return 0;
}
