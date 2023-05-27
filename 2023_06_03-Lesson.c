#include <stdio.h>
#include <string.h>

#define MONTHS 12

int main()
{
	const char *english[MONTHS] =
	{
		"January", "February", "March", "April",
		"May", "June", "July", "August", "September",
		"October", "November", "December"
	};
	const char *french[MONTHS] =
	{
		"janvier", "fevrier", "mars", "avril",
		"mai", "juin", "jullet", "aout", "septembre",
		"octobre", "novembre", "decembre"
	};
	int x;

	/* output months */
	for( x=0; x<MONTHS; x++ )
		printf("%s - %s\n", english[x], french[x]);

	return(0);
}
