#include <stdio.h>

int main()
{
	char buffer[128];

	printf("Type: ");
	scanf("%[^\n]",buffer);
	printf("'%s'\n",buffer);

	return(0);
}
