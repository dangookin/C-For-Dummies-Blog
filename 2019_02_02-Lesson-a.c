#include <stdio.h>

void change(char *s)
{
	*(s+1) = 'i';
}

void output(char *s)
{
	printf("You are %s\n",s);
}

int main()
{
	char string[] = "fat";

	output(string);
	change(string);
	output(string);

	return(0);
}
