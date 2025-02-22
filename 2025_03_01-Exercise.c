#include <stdio.h>
#include <string.h>

int main()
{
	char phrase[] = "Was this the face that launch'd a thousand ships, and burnt the topless towers of Ilium?";
	char find[] = "the";
	char *found;

	puts(phrase);
	found = strstr(phrase,find);
	printf("Found '%s' at offset %d.\n",
			find,
			(int)(found-phrase)
		  );

	return 0;
}
