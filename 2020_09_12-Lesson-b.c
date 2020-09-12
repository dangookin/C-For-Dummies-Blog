#include <stdio.h>

int main()
{
	char buffer[32];

	printf("Type: ");
	scanf("%[$1234567890.,]",buffer);
	printf("Input: '%s'\n",buffer);

	return(0);
}
