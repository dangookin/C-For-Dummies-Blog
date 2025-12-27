#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char filename[] = "sonnet18.txt";
	FILE *fp;
	int count,ch;
	fpos_t pos;
	
	/* open the text file */
	fp = fopen(filename,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		exit(1);
	}
	printf("%s opened\n",filename);

	/* read 256 bytes */
	count = 0;
	while( count<256 )
	{
		ch = fgetc(fp);
		if( ch==EOF )
			break;
		putchar(ch);
		count++;
	}

	/* obtain the file position indicator position */
	puts("\n\n=== Getting file position indicator ===\n");
	fgetpos(fp,&pos);

	/* read another 256 bytes */
	count = 0;
	while( count<256 )
	{
		ch = fgetc(fp);
		if( ch==EOF )
			break;
		putchar(ch);
		count++;
	}

	/* reset the file position indicator */
	puts("\n\n=== Resetting file position indicator ===\n");
	fsetpos(fp,&pos);

	/* read the rest of the file */
	while( (ch=fgetc(fp)) != EOF )
		putchar(ch);

	/* clean-up */
	fclose(fp);
	printf("%s closed\n",filename);
	return 0;
}
