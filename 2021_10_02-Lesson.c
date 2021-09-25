#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>


int main()
{
	char s[] = "Hello there, handsome devil!";

	printf("Before: %s\n",s);
	printf("After: %s\n",strfry(s));

	return(0);
}
