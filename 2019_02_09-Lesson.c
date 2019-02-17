#include <stdio.h>

void array(int size)
{
	char alpha[size];
	int x = 0;

	while(x < size)
	{
		alpha[x] = 'A' + x;
		putchar(alpha[x]);
		x++;
		if( x > 26 )
			break;
	}
	putchar('\n');
}

int main()
{
	array(5);
	array(20);
	array(9);

	return(0);
}

