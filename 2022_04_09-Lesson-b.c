#include <stdio.h>

int main()
{
	int f,b;


	for( f=0 ; f<8; f++ )
	{
		for( b=0; b<8; b++ )
		{
			printf("\x1b[4%c;3%cm %02d:%02d ",
					f+'0',b+'0',
					f,b
				  );
		}
		printf("\x1b[m\n");
	}

	return(0);
}
