#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int r,count;

	/* loop until r = 99 */
	for( srand((unsigned)time(NULL)), r=0, count=1 ;
			r!=99 ;
			count++, r=rand()%100, printf("%3d : %2d\n",count,r)
	   )
		;
	printf("%3d : %2d\n",count,r);

	return(0);
}
