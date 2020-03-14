#include <stdio.h>

int tweval(int a, int b)
{
	if( a<b )
		return(-1);
	if( a>b )
		return(1);
	return(0);
}

int main()
{
	int x,y,r;

	/* get input */
	printf("Enter value 1: ");
	scanf("%d",&x);
	printf("Enter value 2: ");
	scanf("%d",&y);

	/* three-way evaluation */
	r = tweval(x,y);
	if( r<0 )
		printf("%d is less than %d\n",x,y);
	else if( r>0 )
		printf("%d is greater than %d\n",x,y);
	else
		printf("%d and %d are equal\n",x,y);

	return(0);
}
