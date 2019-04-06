#include <stdio.h>

int main()
{
	int x;

	for(x=100;x<1000;x++)
	{
		if( (x % 111) == 0 )
			printf("%d is interesting\n",x);
	}

	return(0);
}

