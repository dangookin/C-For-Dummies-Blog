#include <stdio.h>
#include <time.h>

#define MAX_N 999999999L

void nano_delay(long ns)
{
	struct timespec res;
	long end;

	/* avoid out of range values */
	if( ns<1 || ns>MAX_N )
		return;
	
	/* obtain the current value */
	clock_gettime(CLOCK_REALTIME,&res);
	/* calculate end time */
	end = res.tv_nsec + ns;
	/* wait for the end time */
	while(1)
	{
		clock_gettime(CLOCK_REALTIME,&res);
		if( res.tv_nsec > end )
			break;
	}
}

int main()
{
	long delay;

	for( delay=10; delay<MAX_N; delay*=10 )
	{
		printf("Delay = %ld\n",delay);
		nano_delay(delay);
	}

	return(0);
}
