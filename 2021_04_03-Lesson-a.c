#include <stdio.h>

int main()
{
	signed char a = 0;
	int x;

	for( x=0; x<256; x++ )
	{
		printf("%d\n",a);
		a++;
	}

	return(0);
}
