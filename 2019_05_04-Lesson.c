#include <stdio.h>

int main()
{
	int x, c;
	signed int delta[] = {
		72, 29, 7, 0, 3, -79, 70, 12, -3, -2,
		-77, 36, 29, 13, -78, 39, 40, 0, -4, -2,
		5, -77, -23, -10
	};

	x = c = 0;
	while(x<24)
	{
		c += delta[x];
		putchar(c);
		x++;
	}
	return(0);
}

