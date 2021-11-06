#include <stdio.h>

int main()
{
	struct bitfield {
		unsigned a:1, b:7;
	};
	struct bitfield align;

	align.a = 1;
	align.b = 15;
	printf("size of align = %lu\n",sizeof(align));
	printf("align.c = %u\n",align.a);
	printf("align.d = %u\n",align.b);

	return(0);
}
