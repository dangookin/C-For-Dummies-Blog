#include <stdio.h>

#define RED "\e[31m"
#define NORMAL "\e[m"

int main()
{
	unsigned char ch;

	for( ch=0; ch<=127; ch++ )
	{
		printf("%02X %03d ",ch,ch);
		if( ch<32 )
			printf("%s%c%s",RED,ch+'@',NORMAL);
		else
			putchar(ch);
		putchar('\n');
	}
	return 0;
}
