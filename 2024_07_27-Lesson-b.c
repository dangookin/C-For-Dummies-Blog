#include <stdio.h>

/* output header */
void header(void)
{
	int x;

	for( x=0; x<79; x++ )
	{
		if( x%10==0 )
			putchar('|');
		else
			printf("%d",x%10);
	}
	putchar('\n');
}

int main()
{
	int x,t;
	char *count[8] = {
	   	"Zero", "One", "Two", "Three",
		"Four", "Five", "Six", "Seven"
	};

	/* show tab stops */
	for( x=0; x<8; x++ )
	{
		header();
		for(t=0; t<x; t++ )
			putchar('\t');
		printf("%s\n",count[x]);
	}

	return(0);
}
