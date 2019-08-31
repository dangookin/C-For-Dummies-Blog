#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	struct player {
		char name[32];
		int scores[10];
	} *one;
	int x;

	/* allocate structure */
	one = (struct player *)malloc( sizeof(struct player) * 1 );
	if( one==NULL )
	{
		fprintf(stderr,"Unable to allocate structure\n");
		exit(1);
	}

	/* assign player name */
	strcpy(one->name,"Billy Zlotnick");

	/* create random scores */
	srand( (unsigned)time(NULL) );
	for( x=0; x<10; x++)
		one->scores[x] = rand() % 100;

	/* output results */
	printf("%s's scores:\n",one->name);
	for( x=0; x<10; x++)
		printf(" %3d",one->scores[x]);
	putchar('\n');

	return(0);
}
