#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "HELLO, WORLD!";
	char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	size_t r;

	r = strspn(a,b);
	printf("%zu = '%c'\n",r,a[r]);

	return(0);
}
