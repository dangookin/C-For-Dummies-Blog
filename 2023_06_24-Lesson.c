#include <stdio.h>
#include <string.h>

/* assumes `char` array */
char *key(char *k, char *a[])
{
	int x = 0;

	/* the loop ends on the NULL */
	while( a[x] )
	{
		/* use strcasecmp() if the library has it */
		if( strcmp(k,a[x])==0 )
			return(a[x+1]);
		x+=2;
	}
	return(NULL);
}

int main()
{
	char *months[] =
	{
		"January", "janvier",
		"February", "fevrier",
		"March", "mars",
		"April", "avril",
		"May", "mai",
		"June", "juin",
		"July", "julliet",
		"August", "aout",
		"September", "septembre",
		"October", "octobre",
		"November", "novembre",
		"December", "decembre",
		NULL, NULL
	};
	char a[16];
	char *b;

	printf("Month in English: ");
	/* scanf() doesn't monitor overflow! */
	scanf("%s",a);
	b = key(a,months);
	if( b!=NULL )
		printf("'%s' is '%s' in French\n",a,b);
	else
		printf("'%s' isn't a month name\n",a);

	return(0);
}
