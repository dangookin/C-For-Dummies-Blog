#include <stdio.h>

#define SIZE 15

int getrange(int t,int s[])
{
	int i,start,largest,spread;

	largest = 0;
	start = s[t];
	for( i=t+1; i<SIZE; i++ )
	{
		spread = s[i] - start;
		if( spread > largest )
			largest = spread;
	}

	return(largest);
}

char *timestamp(int t)
{
	static char ts[] = "00:00";
	int hour,minute;

	/* create time stamp string */
	hour = t/2+9;
	if( hour > 12 )
	{
		hour -= 12;
	}
	minute = t%2 ? 30 : 0;
	sprintf(ts,"%02d:%02d",hour,minute);

	/* remove leading zero */
	if( ts[0]=='0' )
		return(ts+1);

	return(ts);
}

int main()
{
	int stock_price[] = {
		8, 9, 7, 6, 8, 10, 12, 11,
		10, 13, 11, 5, 8, 9, 11
	};
	int range[SIZE];
	int t,max_spread,low,high;

	/* evaluate increases */
	for(t=0; t<SIZE; t++)
	{
		range[t] = getrange(t,stock_price);
	}

	/* determine the maximum spread */
	max_spread = low = high = 0;
		/* find the low value */
	for( t=0; t<SIZE; t++ )
	{
		if( range[t] > max_spread )
		{
			max_spread = range[t];
			low = t;
		}
	}
		/* find the high value */
	for( t=low+1; t<SIZE; t++ )
	{
		if( stock_price[t]==stock_price[low]+max_spread )
		{
			high = t;
			break;
		}
	}

	/* output results */
	printf("The best time to buy a share is at %s, $%d/share\n",
			timestamp(low),
			stock_price[low]
		  );
	printf("The best time to sell is at %s, $%d/share\n",
			timestamp(high),
			stock_price[high]
		  );

	return(0);
}
