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
	char *strings[3] = {
		"Hello, world!",
		"This is a string test",
		"Once upon a time, there was a string"
	};
	int x;

	for( x=0; x<3; x++ )
	{
		printf("%s = ",strings[x]);
		increase(strings[x]);
		printf("%s\n",strings[x]);
	}

	return(0);
}
