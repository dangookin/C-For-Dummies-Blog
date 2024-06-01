#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a,b;

	if( argc<3 )
	{
		puts("Enter two values");
		exit(1);
	}

	a = strtol(argv[1],NULL,10);
	b = strtol(argv[2],NULL,10);
	printf("%d + %d = %d\n",a,b,a+b);

	return 0;
}
