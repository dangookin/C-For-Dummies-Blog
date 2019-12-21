#include <stdio.h>

/* becuase I can't include string.h,
   this is my own strcpy() function */
char *strcpy(char *dst, const char *src)
{
	int offset = 0;

	while( *(src+offset) != '\0' )
	{
		*(dst+offset) = *(src+offset);
		offset++;
	}
	*(dst+offset) = '\0';

	return(dst);
}

/* my own strlen() function */
size_t strlen(const char *s)
{
	size_t length = 0;

	while( *s != '\0' )
	{
		length++;
		s++;
	}

	return(length);
}

/* my strlcat() function */
size_t strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	int d_len,s_len,offset,src_index;

	/* obtain initial sizes */
	d_len = strlen(dst);
	s_len = strlen(src);

	/* get the end of dst */
	offset = d_len;

	/* append src */
	src_index = 0;
	while( *(src+src_index) != '\0' )
	{
		*(dst+offset) = *(src+src_index);
		offset++;
		src_index++;
		/* don't copy more than dstsize characters
		   minus one */
		if( offset==dstsize-1)
			break;
	}
	/* always cap the string! */
	*(dst+offset) = '\0';

	return( d_len+s_len );
}

int main()
{
	char first[] = "This is ";
	char last[] = "a potentially long string";
	int r;
	int size = 16;
	char buffer[size];

	strcpy(buffer,first);
	r = strlcat(buffer,last,size);

	puts(buffer);
	printf("Value returned: %d\n",r);
	if( r > size )
		puts("String truncated");
	else
		puts("String was fully copied");

	return(0);
}
