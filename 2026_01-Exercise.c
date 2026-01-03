#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* determine whether all sides are equal */
int all_equal(int a, int b, int c)
{
	if( a==b==c )
		return 1;
	return 0;
}

/* determine whether two sides are equal */
int two_equal(int a, int b, int c)
{
	if( a==b || a==c || b==c )
		return 1;
	return 0;
}

/* detect the longest side */
int longest(int a, int b, int c)
{
	return( b>a ? b>c ? b : c : a>c ? a : c );
}

/* validate three uneven sides as a triangle */
int valid_triangle(int a, int b, int c)
{
	int h;

	h = longest(a,b,c);
	if( h==a && a < b+c )
		return 1;
	if( h==b && b < a+c )
		return 1;
	if( h==c && c < a+b )
		return 1;
	return 0;
}

int main()
{
	int x,y,z;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* generate three random values from 2 to 25 */
	x = rand() % 24 + 2;
	y = rand() % 24 + 2;
	z = rand() % 24 + 2;

	/* validate the data for a triangle */
		/* equilateral */
	if( all_equal(x,y,z) )
		printf("%d - %d - %d is an equilateral triangle\n",x,y,z);
		/* isosceles */
	else if( two_equal(x,y,z) )
		printf("%d - %d - %d is an isosceles triangle\n",x,y,z);
		/* standard */
	else if( valid_triangle(x,y,z) )
	{
		printf("%d - %d - %d is a valid triangle\n",x,y,z);
		printf("%d is the longest side\n",longest(x,y,z) );
	}
		/* invalid */
	else
		printf("%d - %d - %d is not a valid triangle\n",x,y,z);

	return 0;
}
