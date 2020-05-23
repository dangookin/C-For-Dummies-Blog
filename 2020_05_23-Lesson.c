#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.141592
#endif
#define RAD2DEG M_PI/360.0*2.0
#define DEG2RAD 360.0/M_PI/2.0

int main()
{
	printf("Convert radians to degrees: %f\n",RAD2DEG);
	printf("Convert degrees to radians: %f\n",DEG2RAD);

	return(0);
}
