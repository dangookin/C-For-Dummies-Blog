#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *nums;
	int x;

	/* allocate storage for 3 integers */
	nums = (int *)malloc( sizeof(int) * 3 );
	if( nums==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	/* assign the integer values */
	for( x=0; x<3; x++ )
		*(nums+x) = x+1;

	/* output the results */
	printf("%d %d %d\n",
			*(nums+0),
			*(nums+1),
			*(nums+2)
		  );

	return(0);
}
