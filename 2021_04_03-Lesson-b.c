#include <stdio.h>

char *binbin(unsigned char n)
{
    static char bin[9];
    int x;

    for(x=0;x<8;x++)
    {
        bin[x] = n & 0x80 ? '1' : '0';
        n <<= 1;
    }
    bin[x] = '\0';
    return(bin);
}

int main()
{
	signed char a = 0;
	int x;

	for( x=0; x<256; x++ )
	{
		printf("%d\t%s\n",a,binbin(a));
		a++;
	}

	return(0);
}
