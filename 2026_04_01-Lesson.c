#include <stdio.h>

/*
   put the trim() function here
 */

int main()
{
	char *sample[] = {
		"   one   ",
		"\ttwo\n",
		"",
		"    ",
		"a",
		" x ",
		NULL,
		" \t three \n",
		"four",
		"  five",
		"six    ",
		" seven eight "
	};
	int size,x;

	/* obtain array size */
	size = sizeof(sample)/sizeof(sample[0]);

	/* output trimmed strings */
	for( x=0; x<size; x++ )
	{
		/* output string
		   and trimmed string */
	}

	return 0;
}
