#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
	int r;
	struct option args[3] = {
		{ "alpha", 0, NULL, 'a' },
		{ "greek", 0, NULL, 'g' },
		{ 0, 0, 0, 0 }
	};

	/* supress the default error message */
	opterr = 0;

	/* configure long option arguments */

	while( (r=getopt_long(argc,argv,"az",args,0)) != -1 )
	{
		switch(r)
		{
			case 'a':
				/* -a or --alpha argument */
				puts("Option -a or --alpha is set");
				break;
			case 'g':
				/* --greek argument */
				puts("The --greek argument is set");
				break;
			case 'z':
				/* -z argument */
				puts("Option -z is set");
				break;
			case '?':
				printf("Inavlid option: %c\n",optopt);
				break;
			default:
				puts("Unkonwn argument");
		}
	}

	return(0);
}
