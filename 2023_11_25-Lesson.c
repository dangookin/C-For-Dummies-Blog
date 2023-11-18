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

int main()
{
	FILE *dict;
	int length,count,max;
	char word[SIZE],*r;

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* scan for pangrams */
	count = max = 0;
	while( !feof(dict) )
	{
		memset(word,'\0',SIZE);		/* clear buffer */
		r = fgets(word,SIZE,dict);	/* read a word */
		if( r==NULL )
			break;
		length = strlen(word);
		if( length>7 )
		{
			if( char_scan(word,length) )
			{
				if( length > max )
				{
					printf("%s",word);
					max = length;
				}
				count++;
			}
		}
	}
	printf("I found %d pangrams!\n",count);

	/* close */
	fclose(dict);
	
	return(0);
}
