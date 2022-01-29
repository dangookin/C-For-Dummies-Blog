#include <stdio.h>
#include <stdlib.h>

int main()
{
	int r;

	r = system("./twelve");
	printf("Child process exit status = %d\n",r);

	return(0);
}
