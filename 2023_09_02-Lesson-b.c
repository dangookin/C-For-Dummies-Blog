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
	static char name2[] = "memory file two";
	struct mem_file *mfp1,*mfp2;

	mfp1 = mem_open(name1);
	if( mfp1==NULL )
	{
		fprintf(stderr,"Unable to create %s\n",name1);
		exit(1);
	}

	printf("Memory file '%s' created\n",name1);
	printf("Timestamp = %s\n",mfp1->timestamp);

	printf("Press Enter: ");
	getchar();

	mfp2 = mem_open(name2);
	if( mfp2==NULL )
	{
		fprintf(stderr,"Unable to create %s\n",name2);
		exit(1);
	}

	printf("Memory file '%s' created\n",name2);
	printf("Timestamp = %s\n",mfp2->timestamp);

	mem_close(mfp1);
	printf("Memory file '%s' closed\n",name1);
	mem_close(mfp2);
	printf("Memory file '%s' closed\n",name2);

	return(0);
}
