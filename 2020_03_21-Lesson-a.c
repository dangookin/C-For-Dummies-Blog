#include <stdio.h>

int main()
{
	const char filename[] = "gettysburg.txt";
	FILE *fp;
	int ch;

	fp = fopen(filename,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		return(1);
	}

	while( !feof(fp) )
	{
		ch = fgetc(fp);
		if( ch==EOF )
			break;
		fputc(ch,stdout);
	}
	fclose(fp);

	return(0);
}
