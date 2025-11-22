#include <stdio.h>

int main()
{
	constexpr int size = 16;
	int *s;

	printf("The value is %d\n",size);
	s = (int *)&size;
	*s = 0;
	printf("The value is %d\n",size);

	return 0;
}
