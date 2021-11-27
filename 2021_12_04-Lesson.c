#include <stdio.h>
#include <string.h>

int main()
{
	const char *a = "It was a dark and stormy night";
	const char *b =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		;
	size_t r = 0;

	do
	{
		printf("%s\n",a);
		r = strspn(a,b);
		a += r+1;
	}
	while(r<strlen(a));
	printf("%s\n",a);

	return(0);
}
