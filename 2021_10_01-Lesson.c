#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int inc(char *a)
{
	*a += 1;
	if( *a > 'Z' )
	{
		*a = 'A';
		return(TRUE);
	}
	return(FALSE);
}

int main()
{
	char digits[] = "AAAA";

	while(strcmp(digits,"ZZZZ"))
	{
		puts(digits);
		if( inc(&digits[3]) )
			if( inc(&digits[2]) )
				if( inc(&digits[1]) )
					inc(&digits[0]);
	}
	puts(digits);

	return(0);
}

