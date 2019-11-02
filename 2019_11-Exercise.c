#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 12

int yorn(void)
{
	char buffer[SIZE];
	int ch,x;

	/* prompt */
	printf(" (Yes or No)? ");

	/* read stream input */
	fgets(buffer,SIZE,stdin);

	/* check for null input */
	ch = (int)buffer[0];
	if( ch=='\0' || ch==EOF )
		return(0);

	/* replace the newline with null char
	   and convert input to uppercase */
	for( x=0; x<SIZE; x++ )
	{
		if( buffer[x]=='\0' )
			break;
		if( buffer[x]=='\n' )
		{
			buffer[x]='\0';
			break;
		}
		buffer[x] = toupper(buffer[x]);
	}

	/* evaluate results */
		/* return 1 for Yes */
	if( strcmp(buffer,"YES")==0 )
		return(1);
	if( strcmp(buffer,"Y")==0 )
		return(1);
		/* return 2 for No */
	if( strcmp(buffer,"NO")==0 )
		return(2);
	if( strcmp(buffer,"N")==0 )
		return(2);
	/* neither */
	return(0);
}

int main()
{
	int r;

	while(1)
	{
		printf("Would you like to destroy the Earth?");
		r = yorn();
		if( r==1 )
		{
			puts("The Earth will be destroyed.");
			break;
		}
		if( r==2 )
		{
			puts("The Earth will be saved.");
			break;
		}
		puts("Invalid response");
	}

	return(0);
}
