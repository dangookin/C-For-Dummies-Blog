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
	char *strings[3];
	char a[] = "Hello, world!";
	char b[] = "This is a string test";
	char c[] = "Once upon a time, there was a string";
	int x;

	/* allocate pointers */
	strings[0] = a;
	strings[1] = b;
	strings[2] = c;

	/* copy the strings */

	for( x=0; x<3; x++ )
	{
		printf("%s = ",strings[x]);
		increase(strings[x]);
		printf("%s\n",strings[x]);
	}

	return(0);
}
