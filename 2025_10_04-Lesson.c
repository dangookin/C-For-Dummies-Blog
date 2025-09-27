#include <stdio.h>

/* arguments determine buffer sizes
   return value:
   negative for overflow, chars cut
   positive for underflow, chars left in the buffer
   zero for a perfect copy, no wasted space
 */   
int stringcopy(char *dest, size_t dsize, const char *src, size_t ssize)
{
	int flow,x;

	/* test the buffer fit */
	flow = dsize-ssize;

	/* if overflow, copy only dsize characters */
	if( flow<0 )
	{
		for( x=0; x<dsize-1; x++ )
			*(dest+x) = *(src+x);
		*(dest+x) = '\0';
	}
	/* if underflow, copy the entire string */
	/* same condition apples to equal buffer size */
	else
	{
		for( x=0; x<ssize; x++ )
			*(dest+x) = *(src+x);
		*(dest+x) = '\0';
	}

	return(flow);
}

int main()
{
	const char size=16;
	char dest[size];
	char src[] = "The string is the thing";
	int r;

	/* copy the string */
	r = stringcopy(dest,size,src,sizeof(src)-1);
	/* test result */
	if( r<0 )
	{
		puts("String overflow");
		printf("'%s' copied to '%s'\n",src,dest);
	}
	else if( r>0 )
	{
		puts("String underflow");
		printf("'%s' copied to '%s'\n",src,dest);
	}
	else
	{
		puts("String fully copied");
		printf("'%s' copied to '%s'\n",src,dest);
	}

	return 0;
}
