#include <stdio.h>

int main()
{
	const int count = 30;
	int *c;

	printf("The count is %d\n",count);
	c = (int *)&count;
	*c = 0;
	printf("The count is %d\n",count);

	return 0;
}
