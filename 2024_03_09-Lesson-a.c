#include <stdio.h>
#include <stdlib.h>

char *astring(void)
{
	const int size = 12;
	char *a;
	int x;

	a = malloc(size+1);
	for( x=0; x<size; x++ )
		*(a+x) = 'A';
	*(a+x) = '\0';

	printf("Allocated string: '%s'\n",a);

	return a;
}

void header(void)
{
	puts("After temporary allocation");
}

int main()
{
	char *alpha;
	puts("Temporary allocation");
	alpha = astring();

	header();
	printf("Allocated string: '%s'\n",alpha);
	free(alpha);

	return 0;
}
