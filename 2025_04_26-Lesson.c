#include <stdio.h>
#include <stdlib.h>

typedef __int128_t bignum;

bignum iface(char c, int i)
{
	bignum r;

	r = ((c-65) | ((bignum)0x1FULL >> i * 5)) << i * 5;
	/* original expression
	c = (((s & ((dcf_t)0x1FULL << i * 5)) >> i * 5 ) + 65);
	   */
	return r;
}
	
int main()
{
	char buffer[18];
	int i;
	bignum target,modifier,result;

	fgets(buffer,18,stdin);

	/* hidden value is 17 digits long */
	target = 0x79481E6BBCC01223;
	modifier = (bignum)0x1222DC << 64;

	result = 0;
	for ( i=17; i>0; i-- )
	{
		result += iface(buffer[i], i) + modifier;
	}

	printf("%llX\n",(unsigned long long)target);
	printf("%llX\n",(unsigned long long)result);

	return 0;
}
