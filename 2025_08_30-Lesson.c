#include <stdio.h>

int main()
{
	char string[] = "Judge me by my size, will you?";
	int len;

	len = size(string);
	printf("The string \"%s\" is %d characters long.\n",
			string,
			len
		  );

	return 0;
}
