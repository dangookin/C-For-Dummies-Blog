#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void output_permissions(mode_t m)
{
	putchar( m & S_IRUSR ? 'r' : '-' );
	putchar( m & S_IWUSR ? 'w' : '-' );
	putchar( m & S_IXUSR ? 'x' : '-' );
	putchar( m & S_IRGRP ? 'r' : '-' );
	putchar( m & S_IWGRP ? 'w' : '-' );
	putchar( m & S_IXGRP ? 'x' : '-' );
	putchar( m & S_IROTH ? 'r' : '-' );
	putchar( m & S_IWOTH ? 'w' : '-' );
	putchar( m & S_IXOTH ? 'x' : '-' );
	putchar('\n');
}

int main(int argc, char *argv[])
{
	const char *filename;
	struct stat fs;
	int r;

	if( argc<2 )
	{
		puts("Filename required");
		exit(1);
	}

	filename = argv[1];
	printf("Permissions for '%s':\n",filename);
	r = stat(filename,&fs);
	if( r==-1)
	{
		fprintf(stderr,"Error reading '%s'\n",filename);
		exit(1);
	}

	/* output the current permissions */
	puts("Current permissions:");
	output_permissions(fs.st_mode);

	puts("Set group and other write permissions");
	r = chmod( filename, fs.st_mode | S_IWGRP+S_IWOTH );
	if( r!=0)
	{
		fprintf(stderr,"Unable to reset permissions on '%s'\n",filename);
		exit(1);
	}

	puts("Updated permissions:");
	stat(filename,&fs);
	output_permissions(fs.st_mode);

	return(0);
}
