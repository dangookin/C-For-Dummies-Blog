#include <stdio.h>
#include <stdlib.h>

typedef __int128_t bignum;

void iface(bignum s, int i)
{
	bignum w = (bignum)0x1FULL << i * 5;
	bignum x = (s & w) >> i * 5;
	int c = x + 65;
	
	printf("%c",c);
}
	
int main()
{
	int i;
	bignum hidden_value,modifier,result;

	/* hidden value is 17 digits long */
	hidden_value = 0x79481E6BBCC01223;
	modifier = (bignum)0x1222DC << 64;
	result = hidden_value + modifier;

	for ( i=0; i<17; i++ )
	{
		iface(result, i);
	}
}	
