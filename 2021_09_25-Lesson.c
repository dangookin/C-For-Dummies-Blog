#include <stdio.h>
#include <string.h>

int main()
{
	int x;

	puts("System error messages:");
	for( x=1; x<sys_nerr; x++ )
		printf("%3d: %s\n",x,strerror(x));

	return(0);
}
