#include <stdio.h>

int main()
{
	char value[] = "827";
	int cost;

	sscanf(value,"%d",&cost);
	printf("The dress cost $%d\n",cost);

	return(0);
}
