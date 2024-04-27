#include <stdio.h>
#include <math.h>

/* whole population calculation */
double stddev(int v[],int items)
{
	int x,total;
	double mean,variance;

	/* calculate sum */
	total = 0;
	for( x=0; x<items; x++ )
		total += v[x];

	/* calculate the mean (average) */
	mean = (double)total/items;

	/* calculate deviations */
	total = 0;
	for( x=0; x<items; x++ )
		total += (v[x]-mean)*(v[x]-mean);
	variance = (double)total/items;

	return( sqrt(variance) );
}

int main()
{
	int values[] = { 10, 12, 23, 23, 16, 23, 21, 16 };
	int x,items;

	/* output the array's values */
	items = sizeof(values)/sizeof(int);
	printf("Values:");
	for( x=0; x<items; x++ )
	{
		printf(" %2d",values[x]);
	}
	putchar('\n');

	printf("The standard deviation is %.4f\n",
			stddev(values,items)
		  );

	return 0;
}
