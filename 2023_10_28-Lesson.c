#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 32

int main()
{
	FILE *dict;
	int wc,rw;
	char word[SIZE],*r;

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
		r = fgets(word,SIZE,dict);	/* read a word */
		if( r==NULL )
			break;
		wc++;
	}

	/* pluck out a random word */
	rewind(dict);
	srand( (unsigned)time(NULL) );
	rw = rand() % wc;
	while(rw)
	{
		r = fgets(word,SIZE,dict);	/* read a word */
		rw--;
	}
	printf("%s",word);

	/* close */
	fclose(dict);
	
	return(0);
}
