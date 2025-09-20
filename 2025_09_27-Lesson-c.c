#include <stdio.h>
#include <string.h>

int main()
{
	char dest[] = "Don't clobber me!";
	char src[] = "String thing";

	strcpy(dest,src);

	printf("Copied '%s' to '%s'\n",src,dest);

	return 0;
}
