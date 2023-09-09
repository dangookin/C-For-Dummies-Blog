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

/* move the memory offset index
   input- memory file handle, offset, whence
   output- current offset or -1
   whence:  SEEK_SET (start)
   			SEEK_CUR (current)
			SEEK_END (end)
 */
int mem_seek(struct mem_file *m, long position, int whence)
{
	/* return -1 on various errors */
	if( m->address==NULL )
		return(-1);

	/* adjust m->offset value */
	if( whence==SEEK_SET )
	{
		if( position<0 )
			return(-1);
		/* no negative offsets! */
		if( position>m->size )
			return(-1);
		/* set offset from the start */
		m->offset = position;
		return(m->offset);
	}
	else if( whence==SEEK_CUR )
	{
		if( m->offset+position<0 || m->offset+position > m->size )
			return(-1);
		m->offset+=position;
		return(m->offset);
	}
	else if( whence==SEEK_END )
	{
		if( position<0 || m->size-position<0 )
			return(-1);
		m->offset = m->size-position;
		return(m->offset);
	}
	else
		return(-1);
}

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
	int a,r;

	mfp1 = mem_open(name1);
	if( mfp1==NULL )
	{
		fprintf(stderr,"Unable to create %s\n",name1);
		exit(1);
	}
	printf("Memory file '%s' created\n",name1);

	/* write the alphabet to the memory-file */
	for( a='A'; a<='Z'; a++ )
		mem_putc(a,mfp1);

	/* read back in the entire alphabet */
	printf("Reading the entire file: ");
	r = mem_seek(mfp1,0,SEEK_SET);
	if( r==-1)
	{
		fprintf(stderr,"Position error\n");
		exit(1);
	}
	for( a=0; a<26; a++ )
		putchar( mem_getc(mfp1) );
	putchar('\n');

	/* read the last ten characters */
	printf("Reading the last ten characters: ");
	r = mem_seek(mfp1,10,SEEK_END);
	if( r==-1)
	{
		fprintf(stderr,"Position error\n");
		exit(1);
	}
	for( a=0; a<10; a++ )
		putchar( mem_getc(mfp1) );
	putchar('\n');

	/* read the middle ten characters */
	printf("Reading the middle ten characters: ");
		/* position is at the end of the file */
	r = mem_seek(mfp1,-18,SEEK_CUR);
	if( r==-1)
	{
		fprintf(stderr,"Position error\n");
		exit(1);
	}
	for( a=0; a<10; a++ )
		putchar( mem_getc(mfp1) );
	putchar('\n');

	mem_close(mfp1);
	printf("Memory file '%s' closed\n",name1);

	return(0);
}
