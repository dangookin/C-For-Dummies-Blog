#include <stdio.h>

int main()
{
	struct human {
		char name[32];
		int age;
		float weight;
	} my;
	int x;

	for( x=0; x<32; x++)
		my.name[x] = '\0';
	my.age = 0;
	my.weight = 0.0;

	return(0);
}
