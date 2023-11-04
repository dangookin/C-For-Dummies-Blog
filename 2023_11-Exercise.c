#include <stdio.h>
#include <string.h>

#define MAX 11
#define TRUE 1
#define FALSE 0

int digit_scan(long a)
{
	int size,x,y;
	char digits[MAX];

	/* convert to a string */
	snprintf(digits,MAX,"%ld",a);
	/* obtain value size */
	size = strlen(digits) + 1;
	/* scan the digits */
	for( x=0; x<size-2; x++ )
	{
		for( y=x+1; y<size-1; y++ )
		{
			if( digits[x] == digits[y] )
			{
				/* not unique */
				return(FALSE);
			}
		}
	}
	return(TRUE);
}

int main()
{
	int unique;
	long v;

	unique = 0;
	for( v=0; v<10000000000; v++ )
	{
		if( digit_scan(v) )
		{
			printf("%ld\n",v);
			unique++;
		}
	}
	printf("%d unique values\n",unique);

	return(0);
}
