#include <stdio.h>

int main()
{
	char tictactoe[27];
	int x,y,z;

	for(x=0;x<3;x++)
		for(y=0;y<3;y++)
			for(z=0;z<3;z++)
				tictactoe[x+y+z] = '.';

	/* display */
	puts("Tic Tac Toe");
	for(x=0;x<3;x++)
	{
		printf("%*c",x+1,' ');
		for(y=0;y<3;y++)
		{
			for(z=0;z<3;z++)
				printf(" %c ",tictactoe[x+y+z]);
			printf("     ");	/* 5 spaces */
		}
		putchar('\n');
	}

	return(0);
}
