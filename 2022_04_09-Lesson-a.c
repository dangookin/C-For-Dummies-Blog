#include <stdio.h>

int main()
{
	int c;
	const char *colors[] = {
		"BLACK", "RED", "GREEN", "YELLOW",
		"BLUE", "MAGENTA", "CYAN", "WHITE"
	};

	for( c=0 ; c<8; c++ )
	{
		printf("%10s: \x1b[3%cm%s\x1b[m\n",
				colors[c],
				c+'0',
				colors[c]
			  );
	}

	return(0);
}
