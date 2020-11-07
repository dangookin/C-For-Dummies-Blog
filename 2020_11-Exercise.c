#include <stdio.h>
#include <time.h>

int monthcount(time_t date)
{
	struct tm *dstruct;
	int months;

	dstruct = localtime(&date);
	/* year is dstruct->tm_year + 1900 */
	/* month is dstruct->tm_mon + 1 */
	months = (dstruct->tm_year+1900) * 12;
	months += dstruct->tm_mon+1;

	return(months);
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
