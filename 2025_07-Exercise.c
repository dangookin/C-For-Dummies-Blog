#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	int ch,offset;

	/* read and store standard input */
	offset = 0;
	while( (ch=getchar()) != EOF )
	{
		/* allocate buffer first time through */
		if( buffer==NULL )
		{
			/* allocate one byte */
			buffer = malloc( sizeof(char) );
			if( buffer==NULL )
			{
				fprintf(stderr,"Unable to allocate buffer\n");
				exit(1);
			}
		}
		else
		{
			/* expand the buffer by one byte */
			offset++;
			buffer = realloc(buffer,sizeof(char) * (offset+1) );
			if( buffer==NULL )
			{
				fprintf(stderr,"Unable to expand storage\n");
				exit(1);
			}
		}
		*(buffer+offset) = ch;
	}

	/* input saved in the buffer, dump the buffer backwards */
	while(offset>=0)
	{
		putchar( *(buffer+offset) );
		offset--;
	}

	/* clean-up */
	free(buffer);
	return 0;
}
