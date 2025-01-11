#include <stdio.h>

int main()
{
	char *a[] = { "I", "good", "language" };
	char *b[] = { "am", "C", "excellent", "an" };
	char *c[] = { "a", "programmer", "very" };

	printf("%s %s %s %s %s %s %s\n",
			a[0],
			b[0],
			c[0],
			c[2],
			a[1],
			b[1],
			c[1]
		  );

	return 0;
}
