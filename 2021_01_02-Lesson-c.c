#include <stdio.h>

#define foreach(a,b) for(int a=0;a<(sizeof(b)/sizeof(b[0]));a++)

int main()
{
	char c[] = "abcdefg";

	foreach(x,c)
		puts("Whee!");

	return(0);
}
