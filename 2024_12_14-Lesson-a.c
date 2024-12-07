#include <stdio.h>

/* translate a word into piglatin */
char *piglatin(char *s)
{
	/* word starts with a vowel, add -hay */
	/* move first consonant/consonant cluster
	   add -ay */
	return s;
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
