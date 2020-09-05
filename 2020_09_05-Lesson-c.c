#include <stdio.h>

int main()
{
	char first[16];
	char last[16];

	printf("Enter your name, first last: ");
	scanf("%s %s",first,last);
	printf("Hello, %s %s\n",first,last);

	return(0);
}
