#include <stdio.h>

int main()
{
	int f,t;

	/* prompt */
	printf("Enter a positive integer: ");
	scanf("%d",&f);
	if( f<1 ) return -1;

	/* output results */
	printf("%d!! = ",f);
	t = f;
	while(f>2)
		t *= (f-=2);
	printf("%d\n",t);

	return 0;
}
