#include <stdio.h>

int main()
{
	char  buffer[BUFSIZ];

	printf("Your name: ");
	fgets(buffer,BUFSIZ,stdin);
	printf("Hello, %s",buffer);

	return 0;
}
