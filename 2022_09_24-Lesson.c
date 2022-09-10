#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *s)
{
	int len,i;
	char *reversed;

	/* obtain string character count */
	len = strlen(s);

	/* +1 for the null character */
	reversed = malloc( sizeof(char) * len +1 );
	/* if memory allocated, fill it with
	   the reversed string */
	if( reversed!=NULL )
	{
		s += len -1;		/* last char */
		i = 0;				/* forward index */
		while(len)
		{
			*(reversed+i) = *s;		/* fill */
			i++;			/* move index forward */
			len--;			/* loop counter */
			s--;			/* backward offset */
		}
		/* cap the string */
		*(reversed+i) = '\0';
	}

	return(reversed);
}

int main()
{
	char string[] = "Here is your sample string";

	printf("Original: %s\n",string);
	printf("Lanigiro: %s\n",strrev(string));

	return(0);
}
