#include <stdio.h>

int main()
{
	struct bitfield {
		int b:4;
	};
	struct bitfield bits;

	bits.b = 5;

	printf("bits.b = %d\n",bits.b);

	return(0);
}
