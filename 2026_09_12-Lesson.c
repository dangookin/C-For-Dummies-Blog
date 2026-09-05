#include <stdio.h>
#include <stdbool.h>

int main()
{
	bool data[] = { 1, 1, 1, 1, 0, 0, 0, 0 };
	int x,d;

	/* build binary character */
	d = 0;
	for( x=0; x<8; x++ )
	{
		d <<= 1;
		d |= data[x];
	}

	printf("0x%X = %c\n",d,d);

	return 0;
}
