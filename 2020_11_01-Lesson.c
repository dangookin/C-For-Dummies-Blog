#include <stdio.h>
#include <time.h>

int monthcount(time_t date)
{
}

int main()
{
	int month;
	time_t now;

	time(&now);					/* get the current date/time */
	month = monthcount(now);	/* calculate total number of months */
	printf("This month is number %d\n",month);

	return(0);
}
