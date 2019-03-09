#include <stdio.h>
#include <time.h>

int main()
{
	time_t now = 0;

	printf("The epoch is %s",ctime(&now));

	return(0);
}

