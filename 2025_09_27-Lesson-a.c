#include <stdio.h>
#include <string.h>

int main()
{
	char dest[16];
	char src[] = "The string is the thing";

	strcpy(dest,src);

	printf("%s\n",dest);

	return 0;
}
