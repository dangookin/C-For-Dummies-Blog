#include <stdio.h>
#include <time.h>

int main()
{
	time_t now,then;
	long count;

	/* obtain clock tick Epoch value */
	time(&now);

	/* pause one second */
	then = now;
	while(then==now)
		time(&now);
	/* now a new second has begun
	   start the next "full second" loop */
	then = now;
	count = 0;
	while(then==now)
	{
		count++;
		time(&now);
	}
	printf("Cycles: %ld\n",count);

	return(0);
}
