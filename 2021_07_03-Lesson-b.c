#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int r;

	opterr = 0;
	r = getopt(argc,argv,"ABC");
	printf("The getopt() function returned %d\n",r);

	return(0);
}
