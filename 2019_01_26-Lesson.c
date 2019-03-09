#include <stdio.h>
#include <unistd.h>

int main()
{
	const char filename[] = "gettysburg.txt";
	int r;

	r = access(filename,F_OK);
	if( r == 0 )
		printf("File '%s' exists\n",filename);
	else
		printf("File '%s' cannot be found\n",filename);

	return(0);
}

