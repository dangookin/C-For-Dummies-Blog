#include <stdio.h>

int main()
{
	char buffer[12];
	int r;

	r = snprintf(buffer,12,"The total is %d\n",5+8);

	puts(buffer);
	printf("%d characters stored\n",r);

	return(0);
}
