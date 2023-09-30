/* Look up the dictionary */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DICTIONARY "/usr/share/dict/words"

int main()
{
	int r;

	r = access(DICTIONARY,F_OK);
	if( r==-1 )
		puts("Dictionary file is not installed");
	else
		puts("Dictionary file is installed");

	return(0);
}
