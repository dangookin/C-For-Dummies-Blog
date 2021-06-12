#include <stdio.h>
#include <fnmatch.h>

int main()
{
	char pattern[] = "*.c";
	char string[] = "hello.c";
	int r;

	r = fnmatch(pattern,string,0);
	if( r==0 )
		printf("'%s' matches '%s'\n",
				pattern,
				string
			  );
	else if( r==FNM_NOMATCH )
		printf("'%s' does not match '%s'\n",
				pattern,
				string
			  );
	else
		fprintf(stderr,"fnmatch() error\n");

	return(0);
}
