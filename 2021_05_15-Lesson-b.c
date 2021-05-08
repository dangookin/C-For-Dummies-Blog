#include <stdio.h>

int main()
{
	int array[3] = { 1, 2, 3 };
	int *nums = array;

	printf("%d %d %d\n",
			*(nums+0),
			*(nums+1),
			*(nums+2)
		  );
	return(0);
}
