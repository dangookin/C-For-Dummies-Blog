#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a[] = { 10, 20, 30, 40, 50 };

	srand( (unsigned)time(NULL) );
	printf("%d\n", (rand()%5)[a] );

	return 0;
}
