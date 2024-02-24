#include <stdio.h>

long factorial(long f)
{
	if( f<=1 )
		return(1);
	else
		return(f*factorial(f-1));
}

long derange(long d)
{
	long r,t;

	r = 0;
	t = factorial(d);
	while(d>=0)
	{
		r += (d%2 ? -1 : 1)*t/factorial(d);
		d--;
	}

	return(r);
}

int main()
{
	long a;

	for(a=0; a<14; a++)
		printf("!%ld = %ld\n",a,derange(a));

	return 0;
}
