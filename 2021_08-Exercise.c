#include <stdio.h>

int main()
{
	int x;

	printf("Dec  Oct  Hex  C   \
 Dec  Oct  Hex  C  \
 Dec  Oct  Hex  C  \
 Dec  Oct  Hex  C\n");
	for( x=0; x<32; x++ )
	{
		printf("%3d  %3o  %3x  ^%c | ",
				x, x, x, x+64
			  );
		printf("%3d  %3o  %3x  %c | ",
				x+32, x+32, x+32, x+32
			  );
		printf("%3d  %3o  %3x  %c | ",
				x+64, x+64, x+64, x+64
			  );
		printf("%3d  %3o  %3x  %c \n",
				x+96, x+96, x+96, x+96
			  );
	}

	return(0);
}
