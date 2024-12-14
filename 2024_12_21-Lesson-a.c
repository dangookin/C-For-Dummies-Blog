#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		printf("%s, first vowel is %c\n",s,*si);
		pig = s;	/* temp assignment */
	}

	return pig;
}

int main()
{
	char word[32];
	char *s,*pl;

	printf("Original word: ");
	fgets(word,32,stdin);
	/* remove newline */
	s = word;
	while(*s++)
		if( *s=='\n') *s='\0';

	/* translate to pig latin */
	pl = piglatin(word);

	printf("Translated word: %s\n",pl);
	
	return 0;
}
