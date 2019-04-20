#include <stdio.h>
#include <string.h>

int main()
{
	char text[] = "abcdef";

	if( strchr("aeiouAEIOU",text[0] ) )
		printf("'%s' starts with a vowel\n",text);
	else
		printf("'%s' does not start with a vowel\n",text);

	return(0);
}
