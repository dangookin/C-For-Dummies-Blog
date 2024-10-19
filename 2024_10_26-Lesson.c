#include <stdio.h>
#include <math.h>

int main()
{
	double dividend,divisor,r;

	printf("Enter the dividend (numerator): ");
	scanf("%lf",&dividend);
	printf("Enter the divisor (denominator): ");
	scanf("%lf",&divisor);

	r = remainder(dividend,divisor);
	printf("%.2f/%.2f = %.2f with %.2f remainder\n",
			dividend,
			divisor,
			dividend/divisor,
			r
		  );

	return 0;
}
