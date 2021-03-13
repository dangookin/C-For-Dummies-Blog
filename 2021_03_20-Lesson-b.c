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

	strfmon(buffer,32,"%n",359246.80);
	puts(buffer);

	return(0);
}
