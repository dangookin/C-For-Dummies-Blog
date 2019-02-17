#include <stdio.h>

int main()
{
	int b[] = { 2 ,3 };
	int x;

	b[3] = 10;
	for(x=0;x<4;x++)
		printf("%d\n",b[x]);

	return(0);
}
