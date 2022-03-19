#include <stdio.h>

int main()
{
	FILE *printer;

	printer = popen("lp","w");
	if( printer==NULL )
	{
		fprintf(stderr,"Unable to open `lp`\n");
		return(1);
	}

	fprintf(printer,"Hello, Mr. Printer!\n");

	pclose(printer);
	return(0);
}
