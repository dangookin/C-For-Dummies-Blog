#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	struct player {
		char name[32];
		int scores[10];
	} *p[3];
	int x,y;

	/* allocate structures */
	for( y=0; y<3; y++ )
	{
		p[y] = (struct player *)malloc( sizeof(struct player) * 1 );
		if( p[y]==NULL )
		{
			fprintf(stderr,"Unable to allocate structure %d\n",y);
			exit(1);
		}
	}

	/* assign player names */
	strcpy(p[0]->name,"Billy Zlotnick");
	strcpy(p[1]->name,"Franny Blortz");
	strcpy(p[2]->name,"Oscar Papadapolous");

	/* create random scores */
	srand( (unsigned)time(NULL) );
	for( y=0; y<3; y++)
	{
		for( x=0; x<10; x++)
			p[y]->scores[x] = rand() % 100;
	}

	/* output results */
	for( y=0; y<3; y++)
	{
		printf("%s's scores:\n",p[y]->name);
		for( x=0; x<10; x++)
			printf(" %3d",p[y]->scores[x]);
		putchar('\n');
	}

	return(0);
}
