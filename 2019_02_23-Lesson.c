#include <stdio.h>
#include <stdlib.h>

int main()
{
	int d;

	printf("Type a positive number: ");
	scanf("%d",&d);

	if( d > 0 )
	{
		puts("Thanks!");
		return(EXIT_SUCCESS);
	}
	else
	{
		puts("Wrong!");
		return(EXIT_FAILURE);
	}
}
