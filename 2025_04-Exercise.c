#include <stdio.h>

int main(int argc, char *argv[])
{
	if( argc==11 )
		return argc;
	printf("%d\n",main(argc+1,NULL)-1);

	return argc;
}
