#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	return( strcmp(*(const char **)a,*(const char **)b) );
}

int main()
{
	char *fruit[] = {
		"cantalope", "grapefruit", "fig", "melon",
		"banana", "apple", "kiwi", "lemon"
	};
	char *key;	/* input buffer must be allocated */
	char **r;
	int size;

	/* obtain array size */
	size = sizeof(fruit)/sizeof(char *);

	/* locate a value */
	key = malloc(32);
	if (key==NULL) exit(1);
	printf("Fruit: ");
	scanf("%s",key);

	/* sort the array */
	qsort( fruit, size, sizeof(char *), compare);

	/* locate a value */
	r = bsearch( &key, fruit, size, sizeof(char *), compare );
	if( r!=NULL )
		printf("Key %s found!\n",*r);
	else
		printf("Key %s not found.\n",key);

	return 0;
}
