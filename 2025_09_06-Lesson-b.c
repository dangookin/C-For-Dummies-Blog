#include <stdio.h>

int main()
{
	int array[] = { 10, 20, 30, 40 };
	int *ptr;

	ptr = array;
	printf("%d\n",*ptr);

	return 0;
}
