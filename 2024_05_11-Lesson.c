#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a[5] = { 10, 20, 30, 40, 50 };

	printf("%d\n",a[0]);
	printf("%d\n",a[0+1]);
	printf("%d\n",a[0+1+1]);
	printf("%d\n",a[0+1+1+1]);
	printf("%d\n",a[0+1+1+1+1]);
	
	int x = 30;
	int y = 10;
	printf("%d\n",a[x/y]);

	srand( (unsigned)time(NULL) );
	printf("%d\n",a[rand()%5]);

	return 0;
}
