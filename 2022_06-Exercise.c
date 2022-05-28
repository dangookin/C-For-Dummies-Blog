#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int floors=15,passengers=8;
	int lift_stop[floors];
	int x,p,flr;

	/* seed randomizer */
	srand( (unsigned)time(NULL) );

	/* initialize elevator stops */
	for( x=0; x<floors; x++ )
		lift_stop[x] = 0;

	/* passengers set their levels */
	p = 0;
	while( p<passengers )
	{
		flr = rand() % floors;
		if( lift_stop[flr]==0 )
			lift_stop[flr] = rand()%2 ? 1 : -1;
		else
			lift_stop[flr] = 2;
		p++;
	}

	/* Output results, header row */
	printf("%11s","Floor:");
	for(x=0; x<floors; x++)
		printf(" %2d ",x+1);
	putchar('\n');

	/* Going up */
	printf("%11s","Going up:");
	for(x=0; x<floors; x++)
	{
		if(lift_stop[x]==1 || lift_stop[x]==2)
			printf("  > ");
		else
			printf("    ");
	}
	putchar('\n');

	/* Going down */
	printf("%11s","Going down:");
	for(x=0; x<floors; x++)
	{
		if(lift_stop[x]==-1 || lift_stop[x]==2)
			printf("  < ");
		else
			printf("    ");
	}
	putchar('\n');

	return(0);
}
