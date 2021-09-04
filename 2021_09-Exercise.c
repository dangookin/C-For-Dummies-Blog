#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void scramble(char *p,int len)
{
	char *key;
	int x,r;

	/* allocate the temporary string and
	   fill will null characters */
	key = calloc( len+1, sizeof(char) );
	if( key==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	/* process the string */
	x = 0;
	while(x<len)
	{
		r = rand() % len;		/* generate random value */
		if( !*(key+r) )			/* look for a null char */
		{
			*(key+r) = *(p+x);	/* assign the character */
			x++;				/* increment the offset */
		}
	}

	/* update the scrambled string */
	strcpy( p, key);
}

int main()
{
	char word[] = "Onomatapoeia";

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* scramble the string */
	printf("Original: %s\n",word);
	scramble(word,strlen(word));
	printf("Scrambled: %s\n",word);

	return(0);
}
