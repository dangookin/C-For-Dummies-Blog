#include <stdio.h>
#include <strings.h>

int main()
{
	char buffer[BUFSIZ];

	bzero(buffer, BUFSIZ);
	puts("Buffer initialized");

	return(0);
}
