#include <stdio.h>

int main()
{
	const char normal[] = "Normal output ";
	const char error[] = "Error output ";

	fprintf(stdout,normal);
	fflush(stdout);
	fprintf(stderr,error);
	fflush(stderr);
	fprintf(stdout,normal);
	fflush(stdout);
	fprintf(stderr,error);
	fflush(stderr);
	fprintf(stdout,normal);
	fflush(stdout);
	fprintf(stderr,error);
	fflush(stderr);

	return(0);
}

