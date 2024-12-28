#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* test for vowels */
int isvowel(char a)
{
	if( a=='A' || a=='a' )
		return 1;
	if( a=='E' || a=='e' )
		return 1;
	if( a=='I' || a=='i' )
		return 1;
	if( a=='O' || a=='o' )
		return 1;
	if( a=='U' || a=='u' )
		return 1;
	return 0;
}

/* translate a word into piglatin */
char *piglatin(char *s)
{
	char *si,*pig;

	/* word starts with a vowel, add -hay */
	if( isvowel(*s) )
	{
		pig = malloc( strlen(s)+4+1 );	/* "-hay" + '\0' */
		if( pig==NULL )
			return("Memory Error");
		strcpy(pig,s);
		strcat(pig,"-hay");
	}
	else
	{
	/* move first consonant/consonant cluster
	   add -ay */
		si = s;
		while( !isvowel(*si) )
		{
			si++;
			if( *si=='\0' )
				return("Invalid word");
		}
		pig = malloc( strlen(s)+3+1 );	/* "-ay" + '\0' */
		if( pig==NULL )
		return("Memory Error");
		strcpy(pig,si);
		strcat(pig,"-");
		strncat(pig,s,si-s);
		strcat(pig,"ay");
	}

	return pig;
}

int main()
{
	char sentence[BUFSIZ];
	char *start,*end;
	char save;
	int len;

	printf("Original sentence: ");
	fgets(sentence,BUFSIZ,stdin);
	printf("Piglatin sentence: ");

	/* chop sentence into word chunks */
	start = sentence;
	len = strlen(sentence);
	while(start-sentence<len)
	{
		if( isalpha(*start) )
		{
			end = start;
			while( isalpha(*end) || *end=='\'' )
				end++;
			save = *end;
			*end = '\0';
			printf("%s",piglatin(start));
			start = end+1;
			putchar(save);
		}
		else
		{
			putchar(*start);
			start++;
		}
	}
	
	return 0;
}
