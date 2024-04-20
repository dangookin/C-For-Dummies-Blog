#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *a;

	a = malloc(sizeof(int));

	printf("Enter an integer: ");
	scanf("%d",(int *)a);
	printf("You entered %d\n",*((int *)a));

	return 0;
}
