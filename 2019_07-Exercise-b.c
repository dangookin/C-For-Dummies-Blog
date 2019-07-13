#include <stdio.h>
#include <stdlib.h>

int convert(char *s)
{
	int r = 0;

	while( *s )
	{
		r = (r*10) + (*s-'0');
		s++;
	}

	return(r);
}

int main()
{
	char value[] = "345966";
	int v;

	v = atoi(value);
	printf("%s is %d\n",value,v);
	v = convert(value);
	printf("%s is %d\n",value,v);

	return(0);
}
