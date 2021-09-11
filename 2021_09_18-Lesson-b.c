#include <stdio.h>

int main()
{
	const signed week = 7;
	const char *weekday[week] = {
		"Mon", "Tue", "Wed", "Thu",
		"Fri", "Sat", "Sun"
	};
	int x;

	for ( x=0; x<week; x++ )
		printf("%4s",weekday[x]);
	putchar('\n');

	return(0);
}
