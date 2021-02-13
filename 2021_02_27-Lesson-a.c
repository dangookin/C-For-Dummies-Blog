#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* calculate days in February
   from blog post https://c-for-dummies.com/blog/?p=3134
   this update returns the days of the month, not T/F
*/
int february(int year)
{
    /* if the year is divisible by both 100 and
       400, it's a leap year */
    if( (year%400)==0 )
        return(29);
    /* if the year is divisble by 100, it's not
       a leap year */
    if( (year%100)==0 )
        return(28);
    /* check for 4 year interval, which is redundant
       here, but I'll do it anyway */
    if( (year%4) != 0 )
        return(28);
    /* otherwise, it's a leap year */
    return(29);
}

/* Unix Epoch math */
time_t epoch(int year, int mon, int day)
{
	int days,y,m;
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	/* calculate the number of days */
	days = 0;
	for( y=1970; y<year; y++ )
	{
		for( m=0; m<12; m++ )
		{
			if( m==1 )		/* february */
				days += february(y);
			else
				days += month[m];
		}
	}
	/* calculate final year, months only */
	for( m=0; m<mon-1; m++ )
	{
		if( m==1 )		/* february */
			days += february(y);		/* y value is proper */
		else
		   	days+=month[m];
	}
	/* add the day */
	days += day;
	/* tally up the seconds */
	return (time_t)(days * 24 * 60 * 60);
}

int main(int argc, char *argv[])
{
	int year, month, day;
	time_t now,my_now;
	struct tm *today;
	
	/* get current time */
	now = time(NULL);

	/* obtain invidiual values */
	today = localtime(&now);
	year = today->tm_year+1900;
	month = today->tm_mon+1;
	day = today->tm_mday;

	/* get calculated time_t value */
	my_now = epoch(year,month,day);

	/* output results */
	printf("For %4d %2d %2d:\n",year,month,day);
	printf("time_t value is:    %ld, %s",now,ctime(&now));
	printf("My time_t value is: %ld, %s",my_now,ctime(&my_now));

	return(0);
}
