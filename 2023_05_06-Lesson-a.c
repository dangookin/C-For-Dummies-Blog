#include <stdio.h>
#include <time.h>

int main()
{
	struct timespec res;

	clock_gettime(CLOCK_REALTIME,&res);
	printf("Seconds: %lu\nNanoseconds: %lu\n",
			res.tv_sec,
			res.tv_nsec
		  );

	return(0);
}
