#include <stdio.h>
#include <time.h>

int main()
{
	time_t now;
	struct tm *today;
	const char *day[] = { "Sunday", "Monday",
		"Tuesday", "Wednesday", "Thursday",
		"Friday", "Saturday" };
	const char *month[] = { "January", "February",
		"March", "April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };

	/* get today's date */
	time(&now);
	today = localtime(&now);
	printf("Today is %s, %d %s %d\n",
			day[today->tm_wday],
			today->tm_mday,
			month[today->tm_mon],
			today->tm_year+1900
		  );

	/* output yesterday's date */

	return(0);
}
