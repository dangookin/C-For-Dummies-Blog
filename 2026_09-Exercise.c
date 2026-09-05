#include <stdio.h>

int main()
{
	int count;
	char c;
	unsigned char uc;

	/* initialize counting variable */
	count = 1;

	/* signed test */
	while(count)
	{
		c = (signed char)count;
		if( c<0 )
		{
			printf("'signed char' overflow at %d\n",count-1);
			break;
		}
		count++;
	}

	/* unsigned test */
	while(count)
	{
		uc = (unsigned char)count;
		if( uc==0 )
		{
			printf("'unsigned char' overflow at %d\n",count-1);
			break;
		}
		count++;
	}

	return 0;
}
