#include <stdio.h>

int main()
{
	struct bitfield {
		unsigned b:5;
	};
	struct bitfield bits;

	for( bits.b=0x0; bits.b<=0xF; bits.b++ )
		printf("bits.b = %X\n",bits.b);

	return(0);
}
