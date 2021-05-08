#include <stdio.h>

int main()
{
	int *nums = { 1, 2, 3 };

	printf("%d %d %d\n",
			*(nums+0),
			*(nums+1),
			*(nums+2)
		  );
	return(0);
}
