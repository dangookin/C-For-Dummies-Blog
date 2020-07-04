#include <stdio.h>

int main()
{
	int v[5] = { 5, 3, 8, 7, 2 };
	int a,b;

	for(a=0;a<5;a++)
	{
		printf("%d: ",a+1);
		for(b=0;b<v[a];b++)
			putchar('*');
		printf(" (%d)\n",v[a]);
	}

	return(0);
}
