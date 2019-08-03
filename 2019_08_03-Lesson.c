#include <stdio.h>
#include <math.h>

int main()
{
	double max,min,f;
   
	f = 0.0;
	max = nextafter(f,1.0);
	min = nextafter(f,-1.0);
	printf("%e max is %e\n",f,max);
	printf("%e min is %e\n",f,min);

	return(0);
}
