#include <stdio.h>

int main()
{
	char *buffer;
	int r;

	r = asprintf(&buffer,"The total is %d\n",5+8);

	puts(buffer);
	printf("%d characters generated\n",r);

	return(0);
}
