#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *a;
	int *b;

	a = malloc(sizeof(int));
	b = a;

	printf("Enter an integer: ");
	scanf("%d",b);
	printf("You entered %d\n",*b);

	return 0;
}
