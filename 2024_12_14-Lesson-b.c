#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* translate a word into piglatin */
char *piglatin(char *s)
{
	char *pig;

	/* word starts with a vowel, add -hay */
	switch(*s)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			pig = malloc( strlen(s)+4+1 );	/* "-hay" + '\0' */
			if( pig==NULL )
				return("Memory Error");
			strcpy(pig,s);
			strcat(pig,"-hay");
			break;
	/* move first consonant/consonant cluster
	   add -ay */
		default:
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
