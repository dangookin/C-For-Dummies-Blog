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

	strfmon(buffer,32,"Normal: %n",359246.80);
	puts(buffer);
	strfmon(buffer,32,"No grouping characters: %^n",359246.80);
	puts(buffer);
	strfmon(buffer,32,"No currency symbol: %!n",359246.80);
	puts(buffer);
	strfmon(buffer,32,"Left justification: %-30n",359246.80);
	puts(buffer);

	return(0);
}
