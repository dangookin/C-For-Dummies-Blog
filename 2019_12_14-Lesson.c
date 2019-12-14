#include <stdio.h>

size_t strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	int offset;

	/* duplicate the string up to dstsize */
	offset = 0;
		/* guard against silly dstsize values */
	if( dstsize > 0 )
	{
		while( *(src+offset) != '\0' )
		{
			/* bail if dstsize is met */
			if( offset==dstsize )
			{
				offset--;
				break;
			}

			/* duplicate the string */
			*(dst+offset) = *(src+offset);
			offset++;
		}
	}
	/* always remember to cap a created string! */
	*(dst+offset) = '\0';
	
	/* return the string length of src */
	while( *(src+offset) != '\0' )
		offset++;

	return(offset);
}

void test(int size)
{
	char string[] = "Hello there, Venus";
	char buffer[19];
	int r;

	r = strlcpy(buffer,string,size);

	printf("Copied '%s' into '%s', length %d\n",
			string,
			buffer,
			r
		  );
}

int main()
{
	test(19);
	test(10);
	test(1);
	test(0);

	return(0);
}
