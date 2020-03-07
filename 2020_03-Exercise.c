#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned char buffer[16];
	int offset,r,x;

	/* check for arguments */
	if( argc<2 )
	{
		puts("Dump a file in hexadecimal/ASCII");
		puts("Format: dump filename");
		return(1);
	}

	/* open the file */
	fp = fopen(argv[1],"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open file %s\n",argv[1]);
		return(1);
	}
	printf("Dump of '%s':\n",argv[1]);

	/* main dumping loop */
	offset = 0;
	while( !feof(fp) )
	{
		r = fread(buffer,sizeof(unsigned char),16,fp);
		/* break on EOF */
		if( r==0 )
			break;
		/* print offset */
		printf("%04X ",offset);
		/* print hex values */
		for( x=0; x<r; x++ )
		{
			printf(" %02X",buffer[x]);
			if( x==7 )
				printf(" -");
		}
		/* fill in the rest of a blank row */
		if( r<16 )
		{
			for( x=r; x<16; x++ )
			{
				printf("   ");
				if( x==7 )
					printf("  ");
			}
		}

		/* print ASCII */
		printf("   ");
		for( x=0; x<r; x++)
		{
			if( buffer[x]<32 || buffer[x]>126 )
				putchar('.');
			else
				putchar(buffer[x]);
		}
		putchar('\n');
		offset += r;
	}
	printf(" %d total bytes\n",offset);

	/* close the file */
	fclose(fp);

	return(0);
}
