#include <stdio.h>

int main()
{
	int ch,count,max,line,maxline;

	/* initialize */
	count = max = maxline = 0;
	line = 1;

	while(1)
	{
		ch = getchar();
		if( ch == EOF )
			break;
		if( ch == '\n' )
		{
			if( count > max )
			{
				max = count;
				maxline = line;
			}
			count = 0;
			line++;
		}
		else
		{
			count++;
		}
	}
	printf("Line %d has %d characters.\n",maxline,max);

	return(0);
}

