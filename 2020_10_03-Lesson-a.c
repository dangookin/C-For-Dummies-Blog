#include <stdio.h>
#include <unistd.h>

int main()
{
	char *term;

	term = ttyname(0);
	printf("This is terminal %s\n",term);

	return(0);
}
