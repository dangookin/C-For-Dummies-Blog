#include <stdio.h>

int main()
{
	char value[] = "827";
	int cost,r;

	r = sscanf(value,"$%d",&cost);
	if( r!=0 )
		printf("The dress cost $%d\n",cost);

	return(0);
}
