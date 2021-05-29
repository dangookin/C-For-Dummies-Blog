#include <stdio.h>
#include <stdlib.h>
#include <glob.h>

int main()
{
	char **found;
	glob_t gstruct;
	int r;

	r = glob("*.c", GLOB_ERR , NULL, &gstruct);
	/* check for errors */
	if( r!=0 )
	{
		if( r==GLOB_NOMATCH )
			fprintf(stderr,"No matches\n");
		else
			fprintf(stderr,"Some kinda glob error\n");
		exit(1);
	}
	
	/* success, output found filenames */
	printf("Found %zu filename matches\n",gstruct.gl_pathc);
	found = gstruct.gl_pathv;
	while(*found)
	{
		printf("%s\n",*found);
		found++;
	}

	return(0);
}
