#include <stdio.h>

int main()
{
	char buffer[BUFSIZ];

	/* setup the buffer */
	setbuf(stdout,buffer);

	puts("Hold it!");
	puts("Hold it!");
	puts("Go!");
	getchar();
	puts("Thank you.");

	return(0);
}
