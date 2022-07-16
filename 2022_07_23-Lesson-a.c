#include <stdio.h>

char *binString(unsigned char n)
{
	const int width = 8;		/* dealing the 8-bit bytes */
	static char bin[width+1];	/* +1 for the null char */
	int x;

	/* test each bit and set a character for its value */
	for(x=0;x<width;x++)
	{
		bin[x] = n & 0x80 ? '1' : '0';
		n <<= 1;
	}
	bin[width] = '\0';		/* cap the string */

	return(bin);
}

int main()
{
	int value;

	printf("Enter an integer value, 0 to 255: ");
	scanf("%d",&value);
	printf("Binary value is %s\n",binString((unsigned char)value));

	return(0);
}
