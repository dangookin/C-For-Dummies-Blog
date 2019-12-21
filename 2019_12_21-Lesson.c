#include <stdio.h>
#include <string.h>

int main()
{
	char first[] = "This is ";
	char last[] = "a potentially long string";
	int r;
	int size = 64;
	char buffer[size];

	strcpy(buffer,first);
	r = strlcat(buffer,last,size);

	puts(buffer);
	printf("Value returned: %d\n",r);
	if( r > size )
		puts("String truncated");
	else
		puts("String was fully copied");

	return(0);
}
