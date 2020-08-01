#include <stdio.h>

/* return the number of matching digits */
int significance(double a, double b)
{
	const int size = 17;
	char val1[size],val2[size];
	int count;

	/* convert values to strings */
	snprintf(val1,size,"%lf",a);
	snprintf(val2,size,"%lf",b);

	/* count the matching characters */
	count = 0;
	while( val1[count]!='\0' || val2[count]!='\0' )
	{
		if( val1[count] != val2[count] )
			/* bail on mismatch */
			break;
		count++;
	}

	return(count);
}

int main()
{
	int r;
	double v1,v2;

	v1 = 5.98642;
	v2 = 5.98536;

	r = significance(v1,v2);
	printf("The values %lf and %lf show %d digits match\n",
			v1,
			v2,
			r
		  );

	return(0);
}
