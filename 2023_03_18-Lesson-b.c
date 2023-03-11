#include <stdio.h>
#include <time.h>

int main()
{
	time_t now,then;

	/* obtain clock tick Epoch value */
	time(&now);

	/* pause one second */
	then = now;
	while(then==now)
		time(&now);
	/* now a new second has begun
	   start the next "full second" loop */
	printf("%ld\n",now);
	then = now;
	while(then==now)
		time(&now);
	printf("%ld\n",now);

	return(0);
}
