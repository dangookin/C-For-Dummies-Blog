#include <stdio.h>

int main()
{
	int a;
	_BitInt(2) toggle;

	toggle = 0;
	for( a=0; a<14; a++ )
	{
		printf("%d\n",(int)toggle);
		toggle++;
	}

	return(0);
}
