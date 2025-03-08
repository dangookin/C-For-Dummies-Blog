#include <stdio.h>

int main()
{
	char a[8][7] = { "alpha", "bravo", "charlie",
		"delta", "echo", "foxtrot", "golf",
		"hotel"
	};
	int x;

	for( x=0; x<8; x++ )
		puts(a[x]);

	return 0;
}
