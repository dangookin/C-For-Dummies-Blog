#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int r;

	/* suppress getopt()'s error message */
	opterr = 0;

	while( (r=getopt(argc,argv,"az")) != -1 )
	{
		switch(r)
		{
			case 'a':
				puts("-a option is activated");
				/* do A option stuff here */
				break;
			case 'z':
				puts("-z option is activated");
				/* do Z option stuff here */
				break;
			case '?':
				printf("'%c' is an invalid argument\n",optopt);
				break;
			default:
				puts("Unknown argument");
		}
	}

	return(0);
}
