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
		if( deposit[x] < 0.0 )
			debit += deposit[x];
		else
			a += deposit[x];
	}

	/* show results */
	printf("A total of $%.2f in deposits made\n",a);
	printf("A total of %.2f in withdrawals made\n",debit);
	printf("Final balance: $%.2f\n",a+debit);

	return(0);
}
