#include <stdio.h>
#include <string.h>

void test(int size)
{
	char string[] = "Hello there, Venus";
	char buffer[19];
	int r;

	r = strlcpy(buffer,string,size);

	printf("Copied %d characters from '%s' into '%s', length %d\n",
			size,
			string,
			buffer,
			r
		  );
}

int main()
{
	test(19);
	test(10);
	test(1);
	test(0);

	return(0);
}
