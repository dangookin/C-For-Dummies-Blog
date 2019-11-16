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
	unsigned char *bufchar;
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

	return(0);
}
