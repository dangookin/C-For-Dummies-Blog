#include <stdio.h>

int main()
{
	char buffer[12];
	int r;

	r = sprintf(buffer,"The total is %d\n",5+8);

	puts(buffer);
	printf("%d characters stored\n",r);

	return(0);
}
