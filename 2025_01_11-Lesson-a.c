#include <stdio.h>

int main()
{
	int v[] = { 23, 25, 1, 17, 20, 14, 3, 19 };
	int size,key,x;

	/* obtain array size */
	size = sizeof(v)/sizeof(int);

	/* locate a value */
	printf("Input key value: ");
	scanf("%d",&key);
	for( x=0; x<size; x++ )
	{
		if( v[x]==key )
		{
			printf("Key %d found!\n",key);
			return 0;
		}
	}
	printf("Key %d not found.\n",key);

	return 0;
}
