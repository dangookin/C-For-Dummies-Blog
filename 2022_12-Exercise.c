#include <stdio.h>
#include <stdlib.h>

struct film {
	char title[32];
	int year;
};

int compare(const void *a, const void *b)
{
	struct film one,two;

	one = *(struct film *)a;
	two = *(struct film *)b;

	return( one.year - two.year );
}

int main()
{
	const int size = 9;
	struct film bond[size] = {
		{ "Casino Royale", 2006 },
		{ "Dr. No", 1962 },
		{ "GoldenEye", 1995 },
		{ "Goldfinger", 1964 },
		{ "Moonraker", 1979 },
		{ "Octopussy", 1983 },
		{ "Skyfall", 2012 },
		{ "Spectre", 2015 },
		{ "Thunderball", 1965 }
	};
	int x;

	/* sort the list by year */
	qsort(bond,size,sizeof(struct film),compare);

	/* output results */
	for( x=0; x<size; x++ )
		printf("%d, %s\n",
				bond[x].year,
				bond[x].title
			  );

	return(0);
}
