#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *makedata(int s)
{
	int x,*data;

	/* allocate 'size' storage */
	data = malloc( sizeof(int) * s );
	if( data==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* assign random values, 1 through 999 */
	for( x=0; x<s; x++ )
		*(data+x) = rand() % 999 + 1;

	return(data);
}

int main()
{
	int *v,size,key,x;

	/* obtain size 'n' 100 < n < 1000 */
	srand( (unsigned)time(NULL) );		/* seed randomizer */
	size = rand() % 900 + 100;
	printf("Dataset size = %d\n",size);

	/* create data */
	v = makedata(size);

	/* locate a value */
	printf("Input key value: ");
	scanf("%d",&key);
	for( x=0; x<size; x++ )
	{
		if( *(v+x)==key )
		{
			printf("Key %d found!\n",key);
			return 0;
		}
	}
	printf("Key %d not found.\n",key);

	/* clean-up */
	free(v);
	return 0;
}
