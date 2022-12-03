#include <stdio.h>

int main()
{
	if( __STDC__ )
	{
		printf("The C version is at least C89\n");
#ifdef __STDC_VERSION__
	printf("C standard version: %lu\n",__STDC_VERSION__);
#endif
	}
	else
	{
		printf("Somehow you got ahold of K&R C. Neat!\n");
	}

	return(0);
}
