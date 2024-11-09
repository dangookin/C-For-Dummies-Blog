/* Hex Words */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 32

int main()
{
	FILE *dict;
	int count;
	char word[SIZE],hexword[SIZE],*r,*w;

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* read the dictionary */
	count = 0;
	while( !feof(dict) )
	{
		/* read a word from the dictionary */
		r = fgets(word,SIZE,dict);
		if( r==NULL )	/* no word, done */
			break;

		/* remove newline */
		w = word;
		while(*w)
		{
			if( *w=='\n' )
			{
				*w = '\0';
				break;
			}
			w++;
		}
		
		/* pull out only hex characters */
		sscanf(word,"%[ABCDEFabcdef]",hexword);

		/* compare hexword with original word */
		if( strcmp(word,hexword)==0 )
		{
			/* choose words 4 letters long or longer */
			if( strlen(hexword) > 3 )
			{
				printf("%3d: %-10s\n",count+1,hexword);
				count++;
			}
		}
	}


	/* clean-up */
	fclose(dict);
	return(0);
}
