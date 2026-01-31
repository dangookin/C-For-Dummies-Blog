#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* return the first location of a number
   in string s */
char *extract(char *s)
{
	static char *sp = NULL;

	/* check for recall */
	if( s != NULL )
		sp = s;
	else
	{
		/* guard against a NULL string
		   passed the first time */
		if (sp==NULL)
			return(NULL);
		/* find the next non-digit */
		while( isdigit(*sp) )
			sp++;
	}

	/* find the next digit */
	while( *sp != '\0' )
	{
		if( isdigit(*sp) )
		{
			return(sp);
		}
		sp++;
	}

	return(NULL);
}

int main()
{
	char sample[] = "abc10=13!260;1m";
	char *r;
	int v;

	r = extract(sample);
	if( r != NULL )
	{
		v = atoi(r);
		printf("%d\n",v);
		while( (r=extract(NULL)) )
		{
			v = atoi(r);
			printf("%d\n",v);
		}
	}

	return 0;
}
