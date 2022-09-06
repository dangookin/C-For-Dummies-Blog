#include <stdio.h>
#include <stdlib.h>

int main()
{
	const int size = 26*2+1;
	char *a;
	int x,y;
	
	/* allocate storage for two alphabets plus
	   a null character */
	a = malloc( sizeof(char) * size );
	if( a==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* initialize the buffer to all As */
	for( x=0; x<size; x++ )
		*(a+x) = 'A';


	/* manipulate contents */
	for( x=0,y=0; x<26*2; x+=2,y++ )
	{
		*(a+x) = *(a+x) + y;
		*(a+x+1) = *(a+x+1) + y + 32;
	}

	/* output the results */
	*(a+size-1) = '\0';
	puts(a);

	return(0);
}
