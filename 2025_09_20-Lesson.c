#include <stdio.h>

int main()
{
	char word[] = "pneumonoultramicroscopicsilicovolcanoconiosis"; 
	int x = 0;

//	while( putchar( word[x++] ) )
//		;
	while( word[x] )
		putchar(word[x++]);
	putchar('\n');

	return 0;
}
