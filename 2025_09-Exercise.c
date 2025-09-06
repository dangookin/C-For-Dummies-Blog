#include <stdio.h>
#include <ctype.h>

int main()
{
	/* the longest legitimate word in English
	   is about 45 characters */
	const int longest = 64;
	int ch,offset;
	char word[longest];

	offset = 0;
	while( (ch=getc(stdin)) != EOF )
	{
		/* store alphabetic words */
		if( isalnum(ch) || ch=='\'' )
		{
			word[offset] = ch;
			offset++;
			/* check for overflow */
			if( offset==longest )
			{
				fprintf(stderr,"\nInput overflow\n");
				return 1;
			}
		}
		else
		{
			/* if the buffer has content, output
			   it backwards */
			while(offset>0)
			{
				offset--;
				putc(word[offset],stdout);
			}
			/* output the non-alpha character */
			putc(ch,stdout);
		}
	}

	return 0;
}
