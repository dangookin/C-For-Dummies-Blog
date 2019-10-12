#include <locale.h>
#include <wchar.h>

#define HAND_SIZE 5
#define HANDS 9
#define SPADES 0x2660
#define CLUBS 0x2663
#define HEARTS 0x2665
#define DIAMONDS 0x2666

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

struct playing_card {
	wchar_t suit;
	char face[3];
	int value;
};

int straight(struct playing_card p[]);
int flush(struct playing_card p[]);
int fourkind(struct playing_card p[]);
int threekind(struct playing_card p[]);

int main()
{
	struct playing_card hand[HANDS][HAND_SIZE] = {
		{ { DIAMONDS, "5", 5 }, { SPADES, "5", 5 }, { DIAMONDS, "6", 6 }, { DIAMONDS, "9", 9 }, { HEARTS, "9", 9 } },
		{ { SPADES, "2", 4 }, { SPADES, "4", 6 }, { SPADES, "6", 6 }, { SPADES, "10", 10 }, { SPADES, "K", 13 } },
		{ { SPADES, "6", 6 }, { CLUBS, "7", 7 }, { HEARTS, "7", 7 }, { HEARTS, "9", 9 }, { DIAMONDS, "J", 11 } },
		{ { HEARTS, "4", 4 }, { HEARTS, "5", 5 }, { HEARTS, "6", 6}, { HEARTS, "7", 7 }, { HEARTS, "8", 8 } },
		{ { SPADES, "A", 1 }, { HEARTS, "A", 1 }, { DIAMONDS, "A", 1 }, { CLUBS, "A", 1 }, { HEARTS, "K", 13 } },
		{ { DIAMONDS, "A", 1 }, { CLUBS, "4", 4 }, { SPADES, "4", 4 }, { HEARTS, "4", 4 }, { DIAMONDS, "4", 4 } },
		{ { SPADES, "5", 5 }, { CLUBS, "5", 5 }, { DIAMONDS, "5", 5 }, { CLUBS, "9", 9 }, { HEARTS, "9", 9 } },
		{ { SPADES, "A", 1 }, { HEARTS, "9", 9 }, { DIAMONDS, "9", 9 }, { CLUBS, "9", 9 }, { HEARTS, "Q", 12 } },
		{ { SPADES, "A", 1 }, { HEARTS, "A", 1 }, { DIAMONDS, "K", 13 }, { CLUBS, "K", 13 }, { HEARTS, "K", 13 } }
	};
	int x,a,r;

	/* activate wide characters */
	setlocale(LC_ALL,"en_US.UTF-8");

	/* loop for each of the HANDS */
	x = 0;
	while(1)
	{
		if( x==HANDS )
			break;

		/* sort routine would go here,
		   but hands are already sorted */

		/* output hand */
		wprintf(L"Hand %d:",x+1);
		for( a=0; a<HAND_SIZE; a++ )
		{
			wprintf(L" %s",hand[x][a].face);
			putwchar(hand[x][a].suit);
		}

		/* evaluate */
		if( straight(hand[x]) && flush(hand[x]) )
		{
			wprintf(L" - Straight Flush\n");
			x++;
			continue;
		}

		if( straight(hand[x]) )
		{
			wprintf(L" - Straight\n");
			x++;
			continue;
		}

		if( flush(hand[x]) )
		{
			wprintf(L" - Flush\n");
			x++;
			continue;
		}

		if( fourkind(hand[x]) )
		{
			wprintf(L" - Four-of-a-kind\n");
			x++;
			continue;
		}

		r = threekind(hand[x]);
		if( r==2 )
		{
			wprintf(L" - Full House\n");
			x++;
			continue;
		}
		if( r==1 )
		{
			wprintf(L" - Three-of-a-kind\n");
			x++;
			continue;
		}

		putwchar('\n');
		x++;
	}

	return(0);
}

/* All function assume the HAND_SIZE is fixed at 5 */

/* Determine a straight draw */
int straight(struct playing_card p[])
{
	/* straight, ace high */
	if( p[0].value==1 && p[1].value==10 && p[2].value==11 && p[3].value==12 && p[4].value==13 )
		return(TRUE);

	/* other straight */
	if( p[0].value != p[1].value-1 )
		return(FALSE);
	if( p[1].value != p[2].value-1 )
		return(FALSE);
	if( p[2].value != p[3].value-1 )
		return(FALSE);
	if( p[3].value != p[4].value-1 )
		return(FALSE);

	return(TRUE);
}

/* Determine a flush draw */
int flush(struct playing_card p[])
{
	wchar_t s;
	int x;

	/* obtain the first card's suit */
	s = p[0].suit;
	/* compare with all the other cards */
	for( x=1; x<HAND_SIZE; x++ )
	{
		if( s != p[x].suit )
			return(FALSE);
	}

	return(TRUE);
}

/* only two possible hand patterns for
   four-of-a-kind */
int fourkind(struct playing_card p[])
{
	/* test the first four cards */
	if( p[0].value==p[1].value && p[1].value==p[2].value && p[2].value==p[3].value )
		return(TRUE);
	/* test the last four cards */
	if( p[1].value==p[2].value && p[2].value==p[3].value && p[3].value==p[4].value )
		return(TRUE);

	return(FALSE);
}

/* three possible hand patterns for
   three-of-a-kind  - and full house */
int threekind(struct playing_card p[])
{
	/* test the first three cards */
	if( p[0].value==p[1].value && p[1].value==p[2].value )
	{
		/* also test for full house */
		if( p[3].value==p[4].value )
			return(2);
		else
			return(1);
	}

	/* test the next three cards */
	if( p[1].value==p[2].value && p[2].value==p[3].value )
		return(TRUE);
	
	/* test the last three cards */
	if( p[2].value==p[3].value && p[3].value==p[4].value )
	{
		/* also test for a full house */
		if( p[0].value==p[1].value )
			return(2);
		else
			return(1);
	}

	return(FALSE);
}
