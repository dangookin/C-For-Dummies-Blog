#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return( *(int *)a - *(int *)b );
}

int main()
{
	int v[] = { 23, 25, 1, 17, 20, 14, 3, 19 };
	int size,*r,key;

	/* obtain array size */
	size = sizeof(v)/sizeof(int);

	/* locate a value */
	printf("Input key value: ");
	scanf("%d",&key);

	/* sort the array */
	qsort( v, size, sizeof(int), compare);

	/* locate a value */
	r = bsearch( &key, v, size, sizeof(int), compare );
	if( r!=NULL )
		printf("Key %d found!\n",*r);
	else
		printf("Key %d not found.\n",key);

	return 0;
}
