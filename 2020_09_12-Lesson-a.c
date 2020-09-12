#include <stdio.h>

int main()
{
	char buffer[32];

	printf("Type: ");
	scanf("%[ABC]",buffer);
	printf("Input: '%s'\n",buffer);

	return(0);
}
