#include <stdio.h>

int main()
{
	int numbers[6] = {
		[3] = 40,
		[4] = 50
	};
	int x;

	for( x=0; x<6; x++ )
		printf("%d\n",numbers[x]);

	return(0);
}
