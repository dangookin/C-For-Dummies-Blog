#include <stdio.h>

int main()
{
	char *a[] = { "I", "good", "language" };
	char *b[] = { "am", "C", "excellent", "an" };
	char *c[] = { "a", "programmer", "very" };
	char **z[] = { a, b, c };

	printf("%s %s %s %s %s %s\n",
			*(*(z+0)+0),
			*(*(z+1)+0),
			*(*(z+1)+3),
			*(*(z+1)+2),
			*(*(z+1)+1),
			*(*(z+2)+1)
		  );

	return 0;
}
