#include <stdio.h>

int main()
{
	int x;
	float t;

	t = 1.0;
	for( x=2; x<=1000; x*=2 )
	{
		t += 1.0 / (float)x;
		printf("+1/%d = %.4f\n",x,t);
	}
	printf("The sum of the even series is %.4f\n",t);

	return(0);
}
