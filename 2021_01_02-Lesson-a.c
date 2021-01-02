#include <stdio.h>

int main()
{
	float f[] = { 1.4, 5.7, 9.0, 22.7, 88.8 };
	int size,x;

	size = sizeof(f)/sizeof(f[0]);
	for( x=0; x<size; x++ )
		printf("%.1f\n",f[x]);

	return(0);
}
