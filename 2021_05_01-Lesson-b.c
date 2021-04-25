#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[BUFSIZ];

	memset(buffer, '\0', BUFSIZ);
	puts("Buffer initialized");

	return(0);
}
