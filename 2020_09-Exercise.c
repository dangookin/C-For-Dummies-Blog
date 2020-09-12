#include <stdio.h>

/* return string representing integers 0 through 100 */
char *verbal(int n)
{
	char *ones[10] = { "one", "two", "three", "four",
					   "five", "six", "seven", "eight",
					   "nine", "ten" };
	char *teens[9] = { "eleven", "twelve", "thirteen",
					   "fourteen", "fifteen", "sixteen",
					   "seventeen", "eighteen", "nineteen" };
	char *tens[8] = { "twenty", "thirty", "forty",
					  "fifty", "sixty", "seventy",
					  "eighty", "ninety" };
	int dec,uns;
	static char buffer[17];

	/* no need for if-else with returns */
		/* elimninate 0 and 100 */
	if( n==0 )
		return("zero");
	if( n==100 )
		return("one hundred");
	/* process ones */
	if( n<11 )
		return(ones[n-1]);
	/* process teens */
	if( n<20 )
		return(teens[n-11]);
	/* process the rest */
		/* get the ten multiple */
	dec = (n - 20) / 10;
	uns = (n - 20) % 10 - 1;
		/* pull out tens */
	if( uns < 0 )
		return(tens[dec]);
		/* build string for everything else */
	snprintf(buffer,17,"%s %s",tens[dec],ones[uns]);
	return(buffer);
}

int main()
{
	int x;

	for(x=0; x<=100; x++ )
		printf("%s\n",verbal(x));

	return(0);
}
