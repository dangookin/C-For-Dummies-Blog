#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 32
#define TRUE 1
#define FALSE 0

int main()
{
	FILE *dict;
	int length,count;
	char word[SIZE],*r,match[SIZE];
	const char format_string[] = "%[aginprw]";

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* scan for matching words */
	count = 0;
	while( !feof(dict) )
	{
		memset(word,'\0',SIZE);		/* clear buffer */
		memset(match,'\0',SIZE);
		r = fgets(word,SIZE,dict);	/* read a word */
		if( r==NULL )
			break;
		
		/* remove newline */
		r = word;
		while(*r)
		{
			if( *r=='\n' )
			{
				*r = '\0';
				break;
			}
			r++;
		}

		/* process the words */
		length = strlen(word);
		/* greater than four letters */
		if( length>4 )
		{
			sscanf(word,format_string,match);
			if( strcmp(word,match)==0 )
			{
				printf("%s\n",word);
				count++;
			}
		}
	}
	printf("I found %d solutions!\n",count);

	/* close */
	fclose(dict);
	
	return(0);
}
