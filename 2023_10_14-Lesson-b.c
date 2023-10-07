/* Look up the dictionary */
#include <stdio.h>
#include <stdlib.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 32

int main()
{
	FILE *dict;
	int wc;
	char ch;

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* read and tally the words */
	wc = 0;
	while( !feof(dict) )
	{
		ch = fgetc(dict);
		if( ch=='\n' )
			wc++;
	}

	/* results */
	printf("The dictionary file contains %d words\n",wc);

	/* close */
	fclose(dict);
	
	return(0);
}
