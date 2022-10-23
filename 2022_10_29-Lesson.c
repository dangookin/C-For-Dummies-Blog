#include <stdio.h>

#define KM 8

int main()
{
	struct position {
		int row;
		int col;
	};
	struct position pairs[KM] = {
		{ -2,-1 }, { -2, 1 }, { -1, -2 }, { -1, 2 },
		{ 1, -2 }, { 1, 2 }, { 2, -1 }, { 2, 1 }
	};
	int x;

	for( x=0; x<KM; x++ )
	{
		printf("%d, %d\n",
				pairs[x].row,
				pairs[x].col
			  );
	}

	return(0);
}



