#include <stdio.h>
#include <time.h>

int main()
{
	struct timespec res;
	long nano1,nano2;

	/* read consecutive nanosecond values */
	clock_gettime(CLOCK_REALTIME,&res);
	nano1 = res.tv_nsec;
	clock_gettime(CLOCK_REALTIME,&res);
	nano2 = res.tv_nsec;
	printf("Difference: %lu\n",nano2-nano1);

	return(0);
}
