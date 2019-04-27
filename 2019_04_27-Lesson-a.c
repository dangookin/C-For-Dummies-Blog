#include <stdio.h>

int main()
{
	int ch,count,max;

	/* initialize */
	count = max = 0;

	while(1)
	{
		ch = getchar();
		if( ch == EOF )
			break;
		if( ch == '\n' )
		{
			if( count > max )
				max = count;
			count = 0;
		}
		else
		{
			count++;
		}
	}
	printf("Longest line has %d characters.\n",max);

	return(0);
}

