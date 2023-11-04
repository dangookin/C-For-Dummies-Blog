#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 32

int main()
{
	FILE *dict;
	int wc;
	char word[SIZE],*r;

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* scan for four-letter words */
	wc = 0;
	while( !feof(dict) )
	{
		memset(word,'\0',SIZE);		/* clear buffer */
		r = fgets(word,SIZE,dict);	/* read a word */
		if( r==NULL )
			break;
		if( word[2]=='\'' )			/* skip possessives */
			continue;
		if( word[4]=='\n' )			/* four-letter word */
		{
			printf("%s",word);
			wc++;
		}
	}
	printf("I found %d four-letter words!\n",wc);

	/* close */
	fclose(dict);
	
	return(0);
}
