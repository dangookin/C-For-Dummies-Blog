#include <stdio.h>
#include <time.h>

int main()
{
	struct timespec res;
	int count;

	/* loop to read nanosecond values */
	count = 20;
	while( count-- )
	{
		clock_gettime(CLOCK_REALTIME,&res);
		printf("%lu\n",res.tv_nsec);
	}

	return(0);
}
