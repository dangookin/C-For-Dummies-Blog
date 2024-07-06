#include <stdio.h>

void cls(void)
{
	printf("\e[H\e[2J\e[3J");
}

int main()
{
	printf("Prepare to clear the screen!");
	getchar();
	cls();

	return 0;
}
