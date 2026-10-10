#include <stdio.h>

int main()
{
	union real {
		float a;
		long b;
		char c[8];
	};
	union real numb;
	int x;

	numb.a = 10.0;

	printf("The value of numb.a is %f\n",numb.a);
	printf("The value of numb.b is 0x%0lX\n",numb.b);
	printf("Union numb occupies %lu bytes:",sizeof(numb));
	for( x=0; x<8; x++ )
		printf(" %02X",numb.c[x]);
	putchar('\n');

	return 0;
}
