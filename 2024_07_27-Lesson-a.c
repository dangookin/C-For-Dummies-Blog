#include <stdio.h>

int main()
{
	int x;

	/* output header */
	for( x=0; x<79; x++ )
	{
		if( x%10==0 )
			putchar('|');
		else
			printf("%d",x%10);
	}
	putchar('\n');

	/* show tab stops */
	printf("Zero\n");
	printf("\tOne\n");
	printf("\t\tTwo\n");
	printf("\t\t\tThree\n");
	printf("\t\t\t\tFour\n");
	printf("\t\t\t\t\tFive\n");
	printf("\t\t\t\t\t\tSix\n");
	printf("\t\t\t\t\t\t\tSeven\n");

	return(0);
}
