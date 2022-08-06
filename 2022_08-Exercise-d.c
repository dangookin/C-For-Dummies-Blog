#include <stdio.h>

int main()
{
	/* size the array for two alphabets (26)
	   and the null character */
	char a[26*2+1];
	char alpha;
	int x;

	/* do uppercase */
	alpha = 'A';
	for( x=0; x<26*2; x+=2 )
	{
		a[x] = alpha;
		alpha++;
	}

	/* do lowercase */
	alpha = 'a';
	for( x=0; x<26*2; x+=2 )
	{
		a[x+1] = alpha;
		alpha++;
	}

	/* append the null char */
	a[26+26] = '\0';

	/* output result */
	puts(a);

	return(0);
}
