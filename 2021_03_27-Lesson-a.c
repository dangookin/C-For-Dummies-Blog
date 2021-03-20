#include <stdio.h>
#include <locale.h>
#include <monetary.h>

int main()
{
	char buffer[32];
	char *r;

	r = setlocale(LC_ALL,"en_US.UTF-8");
	if( r==NULL )
	{
		fprintf(stderr,"Unable to set locale\n");
		return(1);
	}

	strfmon(buffer,32,"International format: %i",359246.80);
	puts(buffer);
	strfmon(buffer,32,"National format: %n",359246.80);
	puts(buffer);

	return(0);
}
