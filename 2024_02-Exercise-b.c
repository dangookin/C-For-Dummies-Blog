#include <stdio.h>

int main()
{
	int a;

	for( a=0; a<14; a++ )
		printf("%d\n",a&0x01?-1:1);

	return(0);
}
