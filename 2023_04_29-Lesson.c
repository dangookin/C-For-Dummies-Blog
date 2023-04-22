#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *sto,*a;
	const char *b = "string\n";

	sto = malloc( sizeof(char)*strlen(b) + 1 );
	
	a = sto;
	while( ((*a++) = (*b++)) )
		;

	printf("%s",sto);

	return(0);
}
