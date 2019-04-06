#include <stdio.h>

int max(x,y)
{
	if( x > y )
		return(x);
	else
		return(y);
}

int main()
{
	int a,b;

	printf("Input two numbers separated by a space: ");
	scanf("%d %d",&a,&b);

	printf("%d is greater\n",max(a,b));

	return(0);
}

