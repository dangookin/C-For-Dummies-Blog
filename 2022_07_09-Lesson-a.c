#include <stdio.h>

int main()
{
	char *buffer = NULL;
	size_t bufsize = 32;
	size_t characters;

	printf("Type something: ");
	characters = getline(&buffer,&bufsize,stdin);
	printf("%zu characters were read.\n",characters);
	printf("You typed: '%s'\n",buffer);

	return(0);
}

