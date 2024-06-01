#include <stdio.h>
#include <stdlib.h>

int main()
{
	const int size=16;
	char input[size];
	char *next;
	int a,b;

	printf("Enter two values: ");
	fgets(input,size,stdin);
	a = strtol(input,&next,10);
	b = strtol(next,NULL,10);
	printf("%d + %d = %d\n",a,b,a+b);

	return 0;
}
