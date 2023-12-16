#include <stdio.h>

int main()
{
	printf("C version %ld\n",__STDC_VERSION__);
	if( __STDC_VERSION__ >= 202000 )
		puts("C23 features available");
	else
		puts("C23 features unavailable");

	return 0;
}
