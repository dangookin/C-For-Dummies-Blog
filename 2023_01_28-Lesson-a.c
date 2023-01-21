#include <stdio.h>
#include <time.h>

int main()
{
	clock_t start;

	start = clock();
	printf("Processor start time: %lu\n",start);

	return(0);
}
