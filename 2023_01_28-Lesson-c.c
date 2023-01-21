#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int r;
	clock_t start,finish;

	/* obtain start time */
	start = clock();
	printf("Processor start time: %f\n",(float)start/CLOCKS_PER_SEC);

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );
	
	/* loop for a while */
	for(;;)
	{
		r = rand() % 1000;
		if( r==1 )
			break;
	}

	/* obtain finish time */
	finish = clock();
	printf("Processor end time: %f\n",(float)finish/CLOCKS_PER_SEC);

	return(0);
}
