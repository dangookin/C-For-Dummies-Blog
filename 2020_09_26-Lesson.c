#include <stdio.h>

/* return the maximum value in the array */
int maximum(int *a)
{
	int x,max;

	x = max = 0;
	while( *(a+x) != -1 )
	{
		max = max < *(a+x) ? *(a+x) : max;
		x++;
	}

	return(max);
}

/* output the results */
void output(int *a)
{
	int r,x;

	x = 0;
	r = maximum(a);
	printf("Of these values:");
	while(*(a+x) != -1 )
	{
		printf(" %d,",*(a+x));
		x++;
	}
	printf(" the value %d is the greatest.\n",r);
}

int main()
{
	/* all arrays must terminate with -1 */
	int a1[] = { 20, 9, 19, 11, 17, 3, 51, 1, 26, -1 };
	int a2[] = { 909, 400, 765, 1000, 22, 45, -1 };
	int a3[] = { 3, 9, 12, -1 };

	output(a1);
	output(a2);
	output(a3);

	return(0);
}
