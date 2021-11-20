#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "Hello, world!";
	char b[] = " ,!";
	size_t r;

	r = strcspn(a,b);
	printf("%zu = '%c'\n",r,a[r]);

	return(0);
}
