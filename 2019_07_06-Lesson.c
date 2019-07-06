#include <stdio.h>
#include <stdlib.h>

int main()
{
	char x[] = "123456";
	char y[] = "003224";
	char z[] = "0xA72B";
	int a,b,c;

	a = strtol( x, NULL, 10);
	b = strtol( y, NULL, 8);
	c = strtol( z, NULL, 16);

	printf("%s in base 10: %d\n",x,a);
	printf("%s in base 8: %o\n",y,b);
	printf("%s in base 16: %x\n",z,c);

	return(0);
}

