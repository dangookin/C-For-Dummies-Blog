#include <stdio.h>

int main()
{
	int stock_price[] = {
		8, 9, 7, 6, 8, 10, 12, 11,
		10, 13, 11, 5, 8, 9, 11
	};
	int t,hour,minute;

	for(t=0; t<15; t++)
	{
		hour = t/2 + 9;
		if( hour > 12 )
		{
			hour -= 12;
		}
		minute = t%2 ? 30 : 0;
		printf("%2d:%02d Price $%d/share\n",
				hour,
				minute,
				stock_price[t]
			  );
	}

	return(0);
}
