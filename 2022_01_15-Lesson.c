#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int compare(const void *a, const void *b)
{
	return( strcasecmp( *(const char **)a, *(const char **)b ));
}

int main()
{
	const char filename[] = "sonnet18.txt";
	char *buffer;
	const char separators[] = ",.:;!?\n ";
	FILE *fp;
	char *word,**list;
	int offset,ch,count,x,dup,index;
	const int size = 100;
	struct u {
		char *w;
		int d;
	} *unique;

	/* open the file */
	fp = fopen(filename,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		exit(1);
	}

	/* allocate the buffer */
	buffer = malloc( sizeof(char) * BUFSIZ );
	if( buffer==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* read from the file to fill the buffer */
	offset = 0;
	while( !feof(fp) )
	{
		ch = fgetc(fp);			/* read a character */
		if( ch==EOF )			/* bail on EOF */
			break;
		*(buffer+offset) = ch;	/* store chracter */
		offset++;
		if( offset%BUFSIZ==0 )	/* check for full buffer */
		{
			buffer = realloc(buffer,offset+BUFSIZ);
			if( buffer==NULL )
			{
				fprintf(stderr,"Unable to allocate memory\n");
				exit(1);
			}
		}
	}
	*(buffer+offset) = '\0';	/* cap the string */

	fclose(fp);

	list = malloc( sizeof(char *) * size );
	if( list==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	count = 0;
	word = strtok(buffer,separators);
	while( word )
	{
		*(list+count) = word;
		word = strtok(NULL,separators);
		count++;
		if( count%size==0 )
		{
			list = realloc(list,sizeof(char *)*(count+size));
			if( list==NULL )
			{
				fprintf(stderr,"Unable to reallocate memory\n");
				exit(1);
			}
		}
	}

	qsort(list,count,sizeof(char *),compare);

	unique = malloc( sizeof(struct u) * count );
	if( unique==NULL )
	{
		fprintf(stderr,"Unable to allocate structures\n");
		exit(1);
	}

	dup = 1;
	for( x=0,index=0; x<count-1; x+=dup,index++ )
	{
		dup = 1;
		while( strcasecmp(*(list+x),*(list+x+dup))==0 )
		{
			dup++;
		}
		(unique+index)->w = *(list+x);
		(unique+index)->d = dup;
	}
	index--;

	/* unique words... */
	printf("Unique words:\n");
	for( x=0; x<index; x++ )
	{
		if( (unique+x)->d == 1 )
			printf("%s ",
					(unique+x)->w
				  );
	}
	printf("\n\n");

	/* duplicates */
	printf("Words appearing more than once:\n");
	for( x=0; x<index; x++ )
	{
		if( (unique+x)->d > 1 )
			printf("%s (%d) ",
					(unique+x)->w,
					(unique+x)->d
				  );
	}
	printf("\n\n");

	return(0);
}
