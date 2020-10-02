#include <stdio.h>

int main()
{
	int days,d;
	float total;

	printf("Number of days in the month: ");
	scanf("%d",&days);

	total = 0.01;
	for(d=1;d<days;d++)
	{
		total *= 2;
	}
	printf("At the end of %d days, you have $%.2f\n",
			days,
			total
		  );

	return(0);
}
