#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		int age;
		char name[12];
	} man = { 34, "George" };
	void *buffer;
	int *bufint;
	char *bufchar;
	int x;

	/* output the structure */
	printf("%s is %d years old\n",man.name,man.age);

	/* allocate the void buffer */
	buffer = malloc( sizeof(struct person) );
	if( buffer==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* copy memory */
	memcpy(buffer,&man,sizeof(struct person));
	
	/* dump the buffer */
	puts("Buffer dump:");
		/* reference (void)buffer as (char)bufchar */
	bufchar = buffer;
	for( x=0; x<(int)sizeof(struct person); x++ )
	{
		printf(" %02X",*(bufchar+x));
	}
	putchar('\n');

	/* sneak into the buffer */
		/* reference (void)buffer as (int)bufint */
	bufint = (int *)buffer;
		/* reference (void)buffer (offset 4) as (char)bufchar */
	bufchar = (char *)buffer+4;
		/* data can now be accessed directly */
	printf("Int portion: %d\n",*(bufint));
	printf("String portion: %s\n",bufchar);

	return(0);
}
