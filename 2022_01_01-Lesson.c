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
	int offset,ch,count,x;
	const int size = 100;

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

	for( x=0; x<count; x++ )
	{
		printf("%3d:%s\n",x+1,*(list+x));
	}

	return(0);
}
