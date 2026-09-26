#include <stdio.h>

int main()
{
	union text {
		char ch[8];
		long li;
	} t;

	t.li = 0xA216F6C6C6548;
	printf("%s",t.ch);

	return 0;
}
