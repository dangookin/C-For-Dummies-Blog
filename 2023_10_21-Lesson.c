#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 1024

int main()
{
	FILE *dict;
	int maxlen;
	char word[SIZE],*r;

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* find the longest word */
	maxlen = 0;
	while( !feof(dict) )
	{
		r = fgets(word,SIZE,dict);	/* read a word */
		if( r==NULL )
			break;
		if( strlen(word) > maxlen )
		{
			printf("%s",word);
			maxlen = strlen(word);
		}
	}

	/* results */
	printf("The longest word is %d characters long\n",maxlen);

	/* close */
	fclose(dict);
	
	return(0);
}
