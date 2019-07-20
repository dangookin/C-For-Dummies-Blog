#include <stdio.h>

int main()
{
	const char normal[] = "Normal output ";
	const char error[] = "Error output ";

	fprintf(stdout,normal);
	fprintf(stderr,error);
	fprintf(stdout,normal);
	fprintf(stderr,error);
	fprintf(stdout,normal);
	fprintf(stderr,error);

	return(0);
}

