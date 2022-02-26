#include <stdio.h>

int main()
{
	int n;

	printf("The total is %d!%n\n%d characters output above\n",
			500*80,
			&n,
			n
		  );
	printf("n==%d\n",n);

	return(0);
}
