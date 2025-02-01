#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
	printf("isfinite(NAN)         = %s\n",
			isfinite(NAN) ? "TRUE" : "FALSE");
	printf("isfinite(INFINITY)    = %s\n",
			isfinite(INFINITY) ? "TRUE" : "FALSE");
	printf("isfinite(0.0)         = %s\n",
			isfinite(0.0) ? "TRUE" : "FALSE");
	printf("isfinite(DBL_MIN/2.0) = %s\n",
			isfinite(DBL_MIN / 2.0) ? "TRUE" : "FALSE");
	printf("isfinite(1.0)         = %s\n"
			,isfinite(1.0) ? "TRUE" : "FALSE");
	printf("isfinite(exp(800))    = %s\n",
			isfinite(exp(800)) ? "TRUE" : "FALSE");

	return 0;
}
