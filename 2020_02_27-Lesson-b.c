#include <stdio.h>
#include <time.h>

int main()
{
	time_t epoch = 0;

	printf("Time: %s\n",ctime(&epoch));

	return(0);
}
