#include <stdio.h>

int main()
{
	/* constants to set seconds in a minute and seconds in an hour */
	const int minutes = 60;
	const int hours = 60 * minutes;
	int h,m,s;

	/* accept input */
	printf("Enter time in seconds: ");
	scanf("%d",&s);

	/* trim down the chunks */
	h = s/hours;		/* hours rounded */
	s -= h*hours;		/* remaining seconds after removing hours (h) */
	m = s/minutes;		/* minutes rounded */
	s -= m*minutes;		/* remaining seconds after removing minutes (m) */

	printf("That's %d:%02d:%02d\n",h,m,s);

	return(0);
}
