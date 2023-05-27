#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const char *months[12][2] =
	{
		{ "January", "janvier" },
		{ "February", "fevrier" },
		{ "March", "mars" },
		{ "April", "avril" },
		{ "May", "mai" },
		{ "June", "juin" },
		{ "July", "jullet" },
		{ "August", "aout" },
		{ "September", "septembre" },
		{ "October", "octobre" },
		{ "November", "novembre" },
		{ "December", "decembre" }
	};
	int x;

	for( x=0; x<12; x++ )
		printf("%s = %s\n",
				months[x][0],
				months[x][1]
			  );

	return(0);
}
