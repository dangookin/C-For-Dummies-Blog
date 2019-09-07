#include <stdio.h>
#include <time.h>

void ordinal(int d);

int main()
{
	time_t now;
	struct tm *today;
	int tuesday;
	char *days[] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};
	/* this array assumes February to have 28 days */
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	/* obtain the current time */
	time(&now);
	/* translate into date and time fields */
	today = localtime(&now);

	/* output today's day and date */
	printf("Today is %s the %d",
			days[today->tm_wday],
			today->tm_mday
		  );
	ordinal(today->tm_mday);

	/* calculate next Tuesday */
		/* Tuesday is tm_mday value 2 */
	tuesday = (2 - today->tm_wday);
	if( tuesday < 1 )
		tuesday+=7+today->tm_mday;
		/* check for the end of the month */
	if( tuesday > months[today->tm_mon] )
		tuesday -= months[today->tm_mon];
		/* output the result */
	printf("Next Tuesday is the %d",tuesday);
	ordinal(tuesday);

	return(0);
}

/* handle ordinal output */
void ordinal(int d)
{
	if( d>10 && d<14 )
		puts("th");
	else
	{
		switch(d % 10 )
		{
			case 1:
				puts("st");
				break;
			case 2:
				puts("nd");
				break;
			case 3:
				puts("rd");
				break;
			default:
				puts("th");
		}
	}
}

