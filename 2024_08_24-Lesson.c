#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main()
{
	char string[] = "Hello there!";
	char *sp;

	printf("Original string: %s\n",string);
	printf("Original string's address: %p\n",string);
	printf("Original string's size: %zu\n",sizeof(string));

	/* allocate way too much storage */
	sp = malloc(2048);
	if( sp==NULL )
	{
		fprintf(stderr,"Failed to allocate way too much storage\n");
		exit(1);
	}
	for( int x=2048; x<malloc_usable_size(sp)+4; x++ )
		printf("%2X ",*(sp+x));
	putchar('\n');
	
	/* copy the string into storage */
	strcpy(sp,string);
	printf("String copied: '%s'\n",sp);
	printf("New storage address: %p\n",sp);
	printf("New storage size: %zu\n",malloc_usable_size(sp));

	/* reallocate (re-size) the storage */
	sp = realloc(sp,strlen(string)+1);
	if( sp==NULL )
	{
		fprintf(stderr,"Failed to reallocate storage\n");
		exit(1);
	}
	printf("Storage reallocated: '%s'\n",sp);
	printf("Reallocated address: %p\n",sp);
	printf("Reallocated address size: %zu\n",malloc_usable_size(sp));
	
	/* clean up */
	free(sp);
	return(0);
}
