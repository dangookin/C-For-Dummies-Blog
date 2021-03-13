#include <stdio.h>
#include <monetary.h>

int main()
{
	char buffer[32];

	strfmon(buffer,32,"%n",359246.80);
	puts(buffer);

	return(0);
}
