#include <stdio.h>

int main()
{
	const int size = 5;
	int data[size] = {
		5, 8, 2, 6, 9
	};
	int x = 0;

	while( x<size )
		printf("%d\n",data[x++]);

	return(0);
}
