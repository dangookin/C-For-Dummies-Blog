#include <stdio.h>
#include <string.h>

int main()
{
	char source[] = "My text will be copied";
	char destination[] = "123456789012345678901234567890";

	strncpy(destination,source,7);
	printf("%s\n",destination);

	return(0);
}

