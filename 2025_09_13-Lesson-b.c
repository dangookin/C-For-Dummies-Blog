#include <stdio.h>

void output( int a[] )
{
	for( int x=0; x<4; x++ )
		printf("%d\n",*(a+x) );
}

int main()
{
	int array[] = { 10, 20, 30, 40 };

	output(array);

	return 0;
}
