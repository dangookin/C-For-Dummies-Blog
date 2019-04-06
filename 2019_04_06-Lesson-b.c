#include <stdio.h>

int max(x,y)
{
	return( x > y ? x : y );
}

int main()
{
	int a,b;

	printf("Input two numbers separated by a space: ");
	scanf("%d %d",&a,&b);

	printf("%d is greater\n",max(a,b));

	return(0);
}

