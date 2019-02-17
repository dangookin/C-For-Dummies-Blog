#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char *string;

	string= (char *)malloc( sizeof(char)*4 );
	if( string == NULL )
	{
		puts("Unable to allocate string storage");
		exit(1);
	}
	strcpy(string,"fat");

	output(string);
	change(string);
	output(string);

	return(0);
}
