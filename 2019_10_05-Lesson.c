#include <locale.h>
#include <wchar.h>

#define HAND_SIZE 5
#define HANDS 6
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

int main()
{
	struct playing_card hand[HANDS][HAND_SIZE] = {
		{ { DIAMONDS, "5", 5 }, { SPADES, "5", 5 }, { DIAMONDS, "6", 6 }, { DIAMONDS, "9", 9 }, { HEARTS, "9", 9 } },
		{ { SPADES, "4", 4 }, { HEARTS, "6", 6 }, { CLUBS, "6", 6 }, { HEARTS, "7", 7 }, { DIAMONDS, "10", 10 } },
		{ { SPADES, "6", 6 }, { CLUBS, "7", 7 }, { HEARTS, "7", 7 }, { HEARTS, "9", 9 }, { DIAMONDS, "J", 11 } },
		{ { HEARTS, "4", 4 }, { CLUBS, "5", 5 }, { DIAMONDS, "6", 6}, { CLUBS, "7", 7 }, { SPADES, "8", 8 } },
		{ { HEARTS, "A", 1 }, { HEARTS, "3", 3 }, { DIAMONDS, "7", 7 }, { CLUBS, "K", 13 }, { HEARTS, "K", 13 } },
		{ { DIAMONDS, "A", 1 }, { CLUBS, "10", 10 }, { CLUBS, "J", 11 }, { HEARTS, "Q", 12 }, { CLUBS, "K", 13 } }
	};
	int x,a;

	/* activate wide characters */
	setlocale(LC_ALL,"en_US.UTF-8");

	/* loop for each of the HANDS */
	x = 0;
	while(1)
	{
		if( x== HANDS )
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
		if( straight(hand[x]) )
		{
			wprintf(L" - Straight\n");
			x++;
			continue;
		}

		putwchar('\n');
		x++;
	}

	return(0);
}

/* Determine a straight draw */
	/* This function assumes the HAND_SIZE is fixed at 5 */
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
