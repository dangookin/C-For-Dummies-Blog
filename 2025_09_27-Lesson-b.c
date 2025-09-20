#include <stdio.h>
#include <string.h>

int main()
{
	char dest[11];
	char src[] = "The string is the thing";

	strcpy(dest,src);

	printf("Copied '%s' to '%s'\n",src,dest);

	return 0;
}
