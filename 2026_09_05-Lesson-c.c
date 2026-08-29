#include <stdio.h>
#include <stdbool.h>

int main()
{
	bool data = 0x21;

	printf("Size of bool: %lu\n",sizeof(bool));
	printf("Size of 'data': %lu\n",sizeof(data));
	printf("%c\n",(char)data);

	return 0;
}
