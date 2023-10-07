#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int iterations = 100;
	int heads[iterations],tails[iterations];
	int x,y,t,h,h_total,t_total,even,h_max,t_max;
	float h_avg,t_avg;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* 100 sets of 100 flips */
	for( x=0; x<iterations; x++ )
	{
		/* process 100 flips */
		for( y=t=h=0; y<iterations; y++ )
		{
			if( rand()%2 )
				t++;	/* odd is "tails" */
			else
				h++;	/* even is "heads" */
		}
		/* output this round's results */
		printf("Set %3d: %2d Heads, %2d Tails\n",x+1,h,t);
		/* store the data */
		heads[x] = h;
		tails[x] = t;
	}

	/* summary */
	printf("\nResults from %d sets of %d flips:\n",
			iterations,
			iterations
		  );
	/* gather data */
	h_total = t_total = even = h_max = t_max = 0;
	for( x=0; x<iterations; x++ )
	{
		/* obtain totals for averages */
		h_total += heads[x];
		t_total += tails[x];
		/* count even splits */
		if( heads[x]==50 )
			even++;
		/* store maximums */
		if( heads[x] > h_max )
			h_max = heads[x];
		if( tails[x] > t_max )
			t_max = tails[x];
	}

	/* output average of all heads/tails */
	h_avg = (float)h_total/iterations;
	t_avg = (float)t_total/iterations;
	printf("Overall average: %.1f Heads, %.1f Tails\n",
			h_avg,
			t_avg
		  );

	/* number of times it was even */
	printf("Number times it was 50/50: %d\n",even);

	/* greatest number of heads */
	printf("Greatest number of heads: %2d\n",h_max);

	/* greatest number of tails */
	printf("Greatest number of tails: %2d\n",t_max);

	return(0);
}
