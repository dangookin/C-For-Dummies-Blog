#include <stdio.h>

void scale(void)
{
	char s;

	for( s='A'; s<='G'; putchar(s),s++ )
		;
}

int main()
{
	int x;

	for( x=0; x<10; scale(), printf("%d loop\n",x) ,x++ )
		;

	return 0;
}
