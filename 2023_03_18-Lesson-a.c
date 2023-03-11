#include <stdio.h>
#include <time.h>

int main()
{
	time_t now,then;

	/* obtain clock tick Epoch value */
	time(&now);
	printf("%ld\n",now);

	/* pause one second */
	then = now;
	while(then==now)
		time(&now);
	printf("%ld\n",now);

	return(0);
}
