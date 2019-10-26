#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>

#define CARDS 52
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

struct playing_card draw(int d[]);
int straight(struct playing_card p[]);
int flush(struct playing_card p[]);
int fourkind(struct playing_card p[]);
int threekind(struct playing_card p[]);
int pairs(struct playing_card p[]);

int main()
{
	int deck[CARDS];
	struct playing_card hand[HAND_SIZE],temp;
	int a,b,r;

	/* initialize */
		/* seed the randomizer */
	srand((unsigned)time(NULL));
		/* activate wide characters */
	setlocale(LC_ALL,"en_US.UTF-8");
		/* initialize the deck */
	for( a=0; a<CARDS; a++ )
		deck[a] = 0;

	/* draw and sort a hand of HAND_SIZE cards */
	for( a=0; a<HAND_SIZE; a++ )
		hand[a] = draw(deck);

	/* output hand */
	wprintf(L"Your hand is");
	for( a=0; a<HAND_SIZE; a++ )
	{
		wprintf(L" %s%lc",hand[a].face,hand[a].suit);
	}

	/* sort the hand by value */
	for( a=0; a<HAND_SIZE-1; a++)
	{
		for( b=a+1; b<HAND_SIZE; b++ )
		{
			if( hand[a].value > hand[b].value )
			{
				temp = hand[a];
				hand[a] = hand[b];
				hand[b] = temp;
			}
		}
	}

	/* evaluate */
	if( straight(hand) && flush(hand) )
	{
		wprintf(L" - Straight Flush\n");
		return(0);
	}

	if( straight(hand) )
	{
		wprintf(L" - Straight\n");
		return(0);
	}

	if( flush(hand) )
	{
		wprintf(L" - Flush\n");
		return(0);
	}

	if( fourkind(hand) )
	{
		wprintf(L" - Four-of-a-kind\n");
		return(0);
	}

	r = threekind(hand);
	if( r==2 )
	{
		wprintf(L" - Full House\n");
		return(0);
	}
	if( r==1 )
	{
		wprintf(L" - Three-of-a-kind\n");
		return(0);
	}

	r = pairs(hand);
	if( r==2 )
	{
		wprintf(L" - Two Pairs\n");
		return(0);
	}
	if( r==1 )
	{
		wprintf(L" - One Pair\n");
		return(0);
	}

	/* account for ace as the high card */
	if( hand[0].value==1 )
		wprintf(L" - High card: %s%lc\n",hand[0].face,hand[0].suit);
	else
		wprintf(L" - High card: %s%lc\n",hand[4].face,hand[4].suit);

	return(0);
}

/* draw a random card from the deck
   and fill in the structure */
struct playing_card draw(int d[])
{
	wchar_t suits[] = { SPADES, CLUBS, HEARTS, DIAMONDS };
	struct playing_card c;
	int r;

	/* search for an available card */
	while(1)
	{
		r = rand() % CARDS;
		if( d[r] == 0 )
			break;
	}

	/* mark the card as drawn */
	d[r] = 1;

	/* assign suit */
	c.suit = suits[r/13];

	/* assign card value */
	c.value = r % 13 + 1;
	
	/* assign face wide string */
	switch(c.value)
	{
		case 1:
			sprintf(c.face,"A");
			break;
		case 11:
			sprintf(c.face,"J");
			break;
		case 12:
			sprintf(c.face,"Q");
			break;
		case 13:
			sprintf(c.face,"K");
			break;
		default:
			sprintf(c.face,"%d",c.value);
	}
	
	return(c);
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

/* Check for pairs */
int pairs(struct playing_card p[])
{
	/* test the first two cards */
	if( p[0].value==p[1].value )
	{
		/* check for a second pair */
		if( p[2].value==p[3].value || p[3].value==p[4].value )
			return(2);
		else
			return(TRUE);
	}

	/* test the second two cards */
	if( p[1].value==p[2].value )
	{
		/* check for a second pair */
		if( p[3].value==p[4].value )
			return(2);
		else
			return(TRUE);
	}

	/* test for a pair at the 3rd position */
	if( p[2].value==p[3].value )
		return(TRUE);

	/* test for a pair at the final position */
	if( p[3].value==p[4].value )
		return(TRUE);

	return(FALSE);
}
