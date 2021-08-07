#include <stdio.h>

int main()
{
	signed a = -10;
	int values[a];

	printf("Array 'values' occupies %zu bytes of storage\n",sizeof(values));
	printf("It contains %ld elements\n",sizeof(values)/sizeof(int));

	return(0);
}
