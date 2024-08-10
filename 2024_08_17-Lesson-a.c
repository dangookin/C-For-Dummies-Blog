#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char string[] = "Hello there!";
	char *sp;

	printf("Original string: %s\n",string);

	/* allocate way too much storage */
	sp = malloc(2048);
	if( sp==NULL )
	{
		fprintf(stderr,"Failed to allocate way too much storage\n");
		exit(1);
	}
	
	/* copy the string into storage */
	strcpy(sp,string);
	printf("String copied: '%s'\n",sp);

	/* reallocate (re-size) the storage */
	sp = realloc(sp,strlen(string)+1);
	if( sp==NULL )
	{
		fprintf(stderr,"Failed to reallocate storage\n");
		exit(1);
	}
	printf("Storage reallocated: '%s'\n",sp);
	
	/* clean up */
	free(sp);
	return(0);
}
