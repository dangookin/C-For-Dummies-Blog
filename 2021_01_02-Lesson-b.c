#include <stdio.h>

#define foreach(a,b) for(int a=0;a<(sizeof(b)/sizeof(b[0]));a++)

int main()
{
	float f[] = { 1.4, 5.7, 9.0, 22.7, 88.8 };

	foreach(x,f)
		printf("%.1f\n",f[x]);

	return(0);
}
