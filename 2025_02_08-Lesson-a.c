#include <stdio.h>
#include <math.h>

int main()
{
	double a,b;
	int r;

	a = 1.0; b = 0.0;

	/* divide by zero */
	r = fpclassify(a/b);

	switch(r)
	{
		case FP_NAN:
			printf("%.1f/%.1f is not a number (NaN)\n",a,b);
			break;
		case FP_INFINITE:
			printf("%.1f/%.1f is positive or negative infinity\n",a,b);
			break;
		case FP_ZERO:
			printf("%.1f/%.1f is zero\n",a,b);
			break;
		case FP_SUBNORMAL:
			printf("%.1f/%.1f is too small to be represented\n",a,b);
			break;
		case FP_NORMAL:
			printf("%.1f/%.1f is a normal real number\n",a,b);
	}

	return 0;
}
