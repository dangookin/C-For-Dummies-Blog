#include <stdio.h>
#include <stdlib.h>

int main()
{
	char x[] = "";
	char *p;
	int a;

	a = strtol(x,&p,10);
	printf("'%s' evaluates to %d\n",x,a);
	if( p == x )
	{
		printf("'%s' doesn't contain any values\n",x);
	}

	return(0);
}
