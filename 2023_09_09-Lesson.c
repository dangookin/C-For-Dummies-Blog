#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE 2048

struct mem_file {
	void *address;
	char *name;
	int size;
	int offset;
	char *timestamp;
};

/* put a character to a memory file
   input- single character, memory file handle
   output- character written or
   		EOF on failure
 */
int mem_putc(int c, struct mem_file *m)
{
	int *index;

	if( m->address==NULL )
		return(EOF);

	index = m->address+m->size;
	*index = c;

	m->size++;
	/* check for overflow */
	if( (m->size % DEFAULT_SIZE) == 0 )
	{
		m->address=realloc(m->address,m->size-1+DEFAULT_SIZE);
		if( m->address==NULL )
			return(EOF);
	}

	return(c);
}

/* fetch a character from a memory file
   input- memory file handle
   output- character retrieved or
   		EOF on failure
 */
int mem_getc(struct mem_file *m)
{
	int *index;

	if( m->address==NULL )
		return(EOF);

	if( m->offset>m->size )
		return(EOF);

	index = m->address+m->offset;
	m->offset++;
	
	return( *index );
}

/* create a memory file
   input: filename string
   output: pointer to memory file structure,
   		NULL on failure
 */		
struct mem_file *mem_open(char *fn)
{
	struct mem_file *mem_new;
	time_t now;
	
	/* error checking */
	if( fn==NULL )
		return(NULL);

	/* allocate storage for memory file structure */
	mem_new = malloc( sizeof(struct mem_file) );
	if( mem_new==NULL )
		return(NULL);

	/* populate structure */
	mem_new->address = malloc( DEFAULT_SIZE );
	if( mem_new->address==NULL )
		return(NULL);
	mem_new->name=fn;		/* set memory file name */
	mem_new->size = 0;		/* set size */
	mem_new->offset = 0;	/* offset/file pointer */
		/* create timestemp */
	time(&now);
	mem_new->timestamp = ctime(&now);

	return(mem_new);
}

/*
   close memory file, free memory
   input: mem_file structure of an open
   		memory file
 */
void mem_close(struct mem_file *m)
{
	free(m->address);
	free(m);
}

/* test the memory file functions */
int main()
{
	static char name1[] = "memory file";
	struct mem_file *mfp1;
	int a,b;

	mfp1 = mem_open(name1);
	if( mfp1==NULL )
	{
		fprintf(stderr,"Unable to create %s\n",name1);
		exit(1);
	}

	printf("Memory file '%s' created\n",name1);
	printf("Timestamp = %s\n",mfp1->timestamp);

	a = 'A';
	mem_putc(a,mfp1);
	printf("Put character '%c' to file '%s'\n",a,name1);
	b = mem_getc(mfp1);
	printf("Fetched character '%c' from file '%s'\n",b,name1);

	mem_close(mfp1);
	printf("\nMemory file '%s' closed\n",name1);

	return(0);
}
