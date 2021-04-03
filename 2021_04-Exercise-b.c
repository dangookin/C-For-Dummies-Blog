#include <stdio.h>

int main()
{
	float deposit[20] = {
		10.0, -5.0, -10.0, 5.0, 15.0, -10.0, 5.0, -10.0, 5.0, -15.0,
		-5.0, 10.0, 15.0, -15.0, 5.0, 15.0, -5.0, 10.0, -10.0, -5.0
	};
	float a,debit;

	a = debit = 0.0;
	for(int x=0; x<20; x++)
	{
		printf("Bal: $%.2f\t",a);
	
		if( deposit[x] > 0.0 )
		{
			printf("%+.2f ",deposit[x]);
			a += deposit[x];
			/* check to see if debits can be taken */
			if( a+debit>0.0 && debit!=0.0 )
			{
				printf("add debit total %.2f ",debit);
				a += debit;
				debit = 0.0;
			}
			printf("= $%4.2f",a);
		}
		else
		{
			if( a+deposit[x] > 0 )
			{
				printf("%+.2f ",deposit[x]);
				a += deposit[x];
				printf("= $%4.2f",a);
			}
			else
			{
				debit += deposit[x];
				printf("%.2f added to debits",deposit[x]);
			}
		}
		putchar('\n');
	}

	return(0);
}
