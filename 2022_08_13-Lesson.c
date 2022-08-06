#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMonthasInt(const char *monthString);

int main()
{
	const char *month[] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August", "September",
		"October", "November", "December"
	};
	int count = 20;
	int r,m;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* process 20 random month names */
	while(count)
	{
		r = rand() % 12;
		m = getMonthasInt(month[r]);
		printf("%02d %s\n",m,month[r]);
		count--;
	}

	return(0);
}

int getMonthasInt(const char *monthString)
{
	switch( *(monthString) )
	{
		case 'J':
			switch( *(monthString+3) )
			{
				case 'u':
					return(1);		/* JanUary */
				case 'e':
					return(6);		/* JunE */
				case 'y':
					return(7);		/* JulY */
			}
		case 'F':
			return(2);				/* February */
		case 'M':
			switch( *(monthString+2) )
			{
				case 'r':
					return(3);		/* MaRch */
				case 'y':
					return(5);		/* MaY */
			}
		case 'A':
			switch( *(monthString+1) )
			{
				case 'p':
					return(4);		/* APril */
				case 'u':
					return(8);		/* AUgust */
			}
		case 'S':
			return(9);				/* September */
		case 'O':
			return(10);				/* October */
		case 'N':
			return(11);				/* November */
		case 'D':
			return(12);				/* December */
	}
	return(-1);
}
