#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char newvar[] = "langauge";
	const char value[] = "C";

	printf("Setting variable '%s' to '%s'\n",
			newvar,
			value
		  );
	setenv(newvar,value,0);

	printf("Result: '%s'\n",getenv(newvar) );

	printf("Freeing '%s'...",newvar);
	unsetenv(newvar);
	printf("done!\n");

	return 0;
}
