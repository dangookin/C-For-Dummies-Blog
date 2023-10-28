#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 32
#define FALSE 0
#define TRUE 1

int main()
{
	FILE *dict;
	int found,x;
	char input[SIZE],word[SIZE],*r;

	/* gather user input */
	printf("Spell check a word: ");
	fgets(input,SIZE,stdin);

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* scan for matching word (including newline) */
	found = FALSE;
	while( !feof(dict) )
	{
		r = fgets(word,SIZE,dict);	/* read a word */
		if( r==NULL )
			break;
		if( strcmp(input,word)==0 )
		{
			found = TRUE;
			break;
		}
	}

	/* remove newline from input */
	for( x=0; x<SIZE; x++ )
	{
		if( input[x]=='\n' )
		{
			input[x] = '\0';
			break;
		}
	}

	/* output results */
	if(found)
		printf("'%s' is in the dictionary!\n",input);
	else
		printf("I cannot locate '%s' in the dictionary.\n",input);

	/* close */
	fclose(dict);
	
	return(0);
}
