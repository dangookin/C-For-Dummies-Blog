#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;

	printf("Type a letter: ");
	scanf("%c",&c);
	if( c > 'M' )
		abort();
	puts("Whew!");

	return(0);
}
