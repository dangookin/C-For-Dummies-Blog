#include <stdio.h>
#include <time.h>

int main()
{
	time_t now = -63549286400;

	printf("A bad day for Caesar: %s",ctime(&now));

	return(0);
}

