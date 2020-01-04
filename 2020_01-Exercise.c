#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

int main(int argc, char *argv[])
{
	FILE *fp;
	char buffer[SIZE];
	char *r,*b;
	unsigned length;

	/* obtain the filename argument */
	if( argc<2 )
	{
		fprintf(stderr,"Missing filename argument\n");
		exit(1);
	}

	/* open the file */
	fp = fopen(argv[1],"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",argv[1]);
		exit(1);
	}

	/* allocate and initialize the big buffer */
	b = (char *)malloc( sizeof(char)*1 );
	if( b==NULL )
	{
		fclose(fp);
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}
	*b = '\0';
	length = 0;

	/* read the file */
	while( !feof(fp) )
	{
		/* read SIZE bytes of data */
		r = fgets(buffer,SIZE,fp);
		/* confirm data read */
		if( r==NULL )
			break;
		/* reallocate buffer */
		length = strlen(buffer) + strlen(b);
		b = (char *)realloc( b, length+1 );
		if( b==NULL )
		{
			fclose(fp);
			fprintf(stderr,"Memory allocation error\n");
			exit(1);
		}
		strcat(b,buffer);
	}

	/* close */
	fclose(fp);

	/* The file's text is now in the buffer.
	   Process the text from the end back */
		/* decrement the length because the
		   first byte is zero */
	length--;
		/* search for the first non-newline */
	while( *(b+length)=='\n' )
	{
		length--;
	}
		/* preserve the last newline */
	length+=2;
		/* cap the string */
	*(b+length) = '\0';

	/* output the text read */
	printf("%s",b);

	return(0);
}
