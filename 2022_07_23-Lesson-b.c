#include <stdio.h>
#include <stdlib.h>

char *binString(unsigned char n)
{
	const int width = 8;		/* 8-bit bytes */
	char *bin;		/* string storage */
	int x;

	/* allocate storage */
	bin = malloc( width * sizeof(char) +1 );
	if( bin==NULL )
		exit(1);

	/* fill storage */
	for(x=0;x<width;x++)
	{
		bin[x] = n & 0x80 ? '1' : '0';
		n <<= 1;
	}
	bin[width] = '\0';

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
