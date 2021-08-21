#include <stdio.h>

void increase(char *a)
{
	while(*a)
	{
		*a = *a + 1;
		a++;
	}
}

int main()
{
	char a[] = "Hello, world!";

	printf("%s = ",a);
	increase(a);
	printf("%s\n",a);

	return(0);
}
