#include <stdio.h>

int main()
{
	int a;

	for( a=0; a<14; a++ )
		printf("%d\n",a%2?-1:1);

	return(0);
}
