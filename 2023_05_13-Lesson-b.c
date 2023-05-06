#include <stdio.h>
#include <time.h>

int main()
{
	struct timespec res1,res2;

	/* read consecutive nanosecond values */
	clock_gettime(CLOCK_REALTIME,&res1);
	clock_gettime(CLOCK_REALTIME,&res2);
	printf("Difference: %lu\n",res2.tv_nsec-res1.tv_nsec);

	return(0);
}
