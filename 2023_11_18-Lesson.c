#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 32
#define LENGTH 7
#define TRUE 1
#define FALSE 0

int char_scan(char *a)
{
	int size,x,y;

	/* obtain size */
	size = strlen(a) + 1;
	/* scan the characters */
	for( x=0; x<size-2; x++ )
	{
		for( y=x+1; y<size-1; y++ )
		{
			if( a[x] == a[y] )
			{
				/* not unique */
				return(FALSE);
			}
		}
	}
	return(TRUE);
}

int main()
{
	FILE *dict;
	int unique;
	char word[SIZE],*r;

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* scan for LENGTH-letter words */
	unique = 0;
	while( !feof(dict) )
	{
		memset(word,'\0',SIZE);		/* clear buffer */
		r = fgets(word,SIZE,dict);	/* read a word */
		if( r==NULL )
			break;
		if( word[LENGTH-2]=='\'' )			/* skip possessives */
			continue;
		if( word[LENGTH]=='\n' )			/* 7-letter word */
		{
			if( char_scan(word) )
			{
				printf("%s",word);
				unique++;
			}
		}
	}
	printf("I found %d pangrams!\n",unique);

	/* close */
	fclose(dict);
	
	return(0);
}
