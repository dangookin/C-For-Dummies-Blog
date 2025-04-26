#include <stdio.h>

int main()
{
	int x;

	for( x=1; x<11; x++ )
	{
		if( x<10 )
			printf("%d, ",x);
		else
			printf("%d\n",x);
	}

	return 0;
}
