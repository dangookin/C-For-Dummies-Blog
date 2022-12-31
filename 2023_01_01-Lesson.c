#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	char *filename;
	struct stat fs;
	int r;
	
	/* check for filename argument */
	if( argc<2 )
	{
		puts("Specify a filename");
		return(1);
	}

	/* operate from the first argument */
	filename = argv[1];

	r = stat(filename,&fs);
	if( r==-1 )
		printf("Unable to read %s\n",filename);
	else
		printf("%s is %lld bytes long\n",filename,fs.st_size);

	return(0);
}
