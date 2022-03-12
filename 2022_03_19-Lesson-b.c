#include <stdio.h>

int main()
{
	struct human {
		char name[32];
		int age;
		float weight;
	} my;
	int x;
	char *b;

	b = (char *)&my;
	for( x=0; x<sizeof(struct human); x++)
		*(b+x) = 0;

	return(0);
}
