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
	const int total = 100;
	const int size = 5;		/* assume 5 digits max */
	const int columns = 9;
	int count,v,x,y;
	int results[total];
	char fwd[size+1];		/* +1 for the null char */
	char *bkd;

	/* find the palindromic values */
	count = 0;
	v = 1;
	while(count<total)
	{
		/* eliminate single digits */
		if( v < 10 )
		{
			results[count] = v;
			count++;
		}
		else
		{
			snprintf(fwd,size,"%d",v);
			bkd = strrev(fwd);
			if(strcmp(bkd,fwd) == 0 )
			{
				results[count] = v;
				count++;
			}
		}
		v++;
	}

	/* output the results in a fancy table */
	x = 0;
	while( count )
	{
		for( y=0; y<columns; y++ )
		{
			printf("%5d",results[(x*columns)+y]);
			count--;				/* decrement the count */
			if( !count )			/* if count is zero, stop */
				break;
			if( y<columns-1)
				putchar('\t');
		}
		x++;
		putchar('\n');
	}

	return(0);
}
