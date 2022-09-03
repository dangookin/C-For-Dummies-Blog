#include <stdio.h>
#include <string.h>

/* count the zero '0' characters in the string */
int zero_count(char *v)
{
	int a = 0;

	/*
	   - crawl through the string
	   - okay to modify v here
	*/
	while( *v )
	{
		if( *v == '0' )
			a++;		/* count '0' character */
		v++;			/* increment pointer */
	}

	return(a);
}

int main()
{
	const char digits = 6;		/* storage for up to 5 digits */
	const int total = 100;		/* total numbers to find */
	const int columns = 9;		/* number of columns for output table */
	int cyclops,count,len,mid,x,y;
	char buffer[digits];
	int results[total];			/* store the results for fancy output */

	printf("The first %d cyclops numbers\n",total);
	cyclops = count = 0;
	while( count<total )
	{
		sprintf(buffer,"%d",cyclops);
		len = strlen(buffer);
		/* process strings greater than two characters
		   and only odd-length strings */
		if( len>2 && len%2 )
		{
			/* must have only one zero */
			if( zero_count(buffer)==1 )
			{
				mid = len/2;			/* middle character offset */
				if(buffer[mid]=='0' )	/* is zero? */
				{
					/* save the value and update the count */
					results[count] = cyclops;
					count++;
				}
			}
		}

		/* next potential cyclops value */
		cyclops++;
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
