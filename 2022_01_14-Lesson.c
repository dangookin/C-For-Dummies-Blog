#include <stdio.h>

void memzero(void *b, int len)
{
	volatile int x;
	char *a;

	a = (char *)b;
	for( x=0; x<len; x++)
		*(a+x) = 0;
}

int main()
{
	struct human {
		char name[32];
		int age;
		float weight;
	} my;

	memzero(&my,sizeof(struct human));

	return(0);
}
