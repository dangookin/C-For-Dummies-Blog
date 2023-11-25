#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 32
#define TRUE 1
#define FALSE 0

int char_scan(char *a,int len)
{
	int x,y;

	/* eliminate proper nouns */
	if( isupper(a[0]) )
		return(FALSE);

	/* scan the characters */
	for( x=0; x<len-2; x++ )
	{
		for( y=x+1; y<len-1; y++ )
		{
			if( a[x] == a[y] )
			{
				/* not unique */
				return(FALSE);
			}
			if( a[x] == '\'' )
				return(FALSE);
		}
	}
	return(TRUE);
}

char *get_keys(int size)
{
	char *format,*input,*r;

	/* allocate storage */
	format = malloc(sizeof(char) * size + 3);
	input = malloc(sizeof(char) * size + 1 );
	if( format==NULL || input==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	/* prompt for input */
	printf("Enter %d unique letters: ",size);
	fgets(input,size+1,stdin);
	/* confirm minimum */

	/* remove newline */
	r = input;
	while(*r)
	{
		if( *r=='\n' )
		{
			*r = '\0';
			break;
		}
		r++;
	}
	getchar();

	if( strlen(input) < size )
	{
		fprintf(stderr,"Please input %d letters\n",size);
		exit(1);
	}

	/* ensure none of the characters repeat */
	if( !char_scan(input,size) )
	{
		fprintf(stderr,"No letters can repeat\n");
		exit(1);
	}

	/* build format string */
	strcpy(format,"%[");
	strcat(format,input);
	strcat(format,"]");

	/* return the format string */
	return(format);
}

int main()
{
	FILE *dict;
	int length,count;
	char *format_string,word[SIZE],*r,match[SIZE];

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* obtain key letters */
	format_string = get_keys(6);

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
