#include <stdio.h>

int main()
{
	union stow {
		int l;
		char c;
	} s;

	s.l = 0x87654321;
	printf("Union 's' stores: 0x%X\n",s.l);
	printf("But also: %c\n",s.c);

	return 0;
}
