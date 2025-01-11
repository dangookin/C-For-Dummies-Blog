#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct potus {
	int index;
	char *name;
};

int compare(const void *a, const void *b)
{
	char *name1 = ((struct potus *)a)->name;
	char *name2 = ((struct potus *)b)->name;
	return( strcmp(name1,name2) );
}

int main()
{
	struct potus presidents[] = {
		{ 1, "Washington" }, { 2, "Adams" }, { 3, "Jefferson" },
		{ 4, "Madison" }, { 5, "Monroe" }, { 6, "Adams" }
	};
	struct potus *r,*key;
	char input[32];
	int size;

	/* obtain array size */
	size = sizeof(presidents)/sizeof(presidents[0]);
	
	/* obtain input */
	printf("President: ");
	scanf("%s",input);
	/* the key must be a structure to match
	   the index member need not be set */
	/* allocate storage for both the structure
	   as well as the name */
	key = malloc( sizeof(struct potus) );
	key->name = malloc( sizeof(char) * 32 );
	if( key== NULL || key->name==NULL )
	{
		fprintf(stderr,"Unable to allocate structure\n");
		exit(1);
	}
	strcpy(key->name,input);

	/* sort the list */
	qsort(presidents,size,sizeof(struct potus),compare);

	/* locate a value */
	r = bsearch( key, presidents, size, sizeof(struct potus), compare );
	if( r!=NULL )
		printf("Key %s found!\n",r->name);
	else
		printf("Key %s not found.\n",key->name);

	return 0;
}
