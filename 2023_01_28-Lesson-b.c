#include <stdio.h>
#include <time.h>

int main()
{
	clock_t start;

	start = clock();
	printf("Processor start time: %f\n",(double)start/CLOCKS_PER_SEC);

	return(0);
}
