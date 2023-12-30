#include <stdio.h>
#include <limits.h>

int main()
{
	_BitInt(8) supershort;

	supershort = 22;

	printf("The 8-bit variable has a value of %d\n",(int)supershort);
	printf("_BitInt(%d) uses %lu bytes in memory\n",
			BITINT_MAXWIDTH,
			sizeof(_BitInt(BITINT_MAXWIDTH))
		  );

	return 0;
}
