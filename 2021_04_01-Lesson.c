#include <stdio.h>

int main()
{
	float deposit[20] = {
		10.0, -5.0, -10.0, 5.0, 15.0, -10.0, 5.0, -10.0, 5.0, -15.0,
		-5.0, 10.0, 15.0, -15.0, 5.0, 15.0, -5.0, 10.0, -10.0, -5.0
	};
	float a;

	a = 0.0;
	for(int x=0; x<20; x++)
	{
		printf("Bal: $%4.2f\t",a);
		if( deposit[x] > 0 )
			printf("credit %.2f",deposit[x]);
		else
			printf("debit %.2f",deposit[x]);
		/* adjust balance */
		a += deposit[x];
		/* output new balance */
		printf("\t= $%4.2f",a);
		/* flag overdrafts */
		if( a < 0 )
			printf("\t** Overdraft\n");
		else
			putchar('\n');
	}

	return(0);
}
