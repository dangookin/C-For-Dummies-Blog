/* from RosettaCode */
#include <stdio.h>

int main()
{
	int x;

	for( x=1; x<11; x++ )
	{
		printf("%d",x);
		printf( x==10 ? "\n" : ", ");
	}

	return 0;
}
