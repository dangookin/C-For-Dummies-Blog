#include <stdio.h>

#define SIZE 8
#define COLOR_WHITE "\x1b[30;47m"
#define COLOR_CYAN "\x1b[30;46m"
#define COLOR_OFF "\x1b[0m"

void chess_board(void)
{
	int row,col;

	for( row=0; row<SIZE; row++ )
	{
		for( col=0; col<SIZE; col++ )
		{
			if( row%2 )
			{
				if( col%2 )
					printf("%s  ",COLOR_WHITE);
				else
					printf("%s  ",COLOR_CYAN);
			}
			else
			{
				if( col%2 )
					printf("%s  ",COLOR_CYAN);
				else
					printf("%s  ",COLOR_WHITE);
			}
		}
		printf("%s",COLOR_OFF);
		putchar('\n');
	}
}

int main()
{
	chess_board();

	return(0);
}
