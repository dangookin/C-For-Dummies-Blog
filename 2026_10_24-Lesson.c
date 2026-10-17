#include <stdio.h>

int main()
{
	union real {
		float a;
		long b;
	};
	union real numb;
	int x;

	/* gather input */
	printf("Enter a value: ");
	scanf("%f",&numb.a);

	/* output real number value */
	printf("The value %f is stored as: ",numb.a);

	/* read bytes */
	for( x=0; x<32; x++ )
	{
		if( x==1 || x==9 )
		{
			putchar(' ');
		}
		putchar( numb.b & 0x80000000 ? '1' : '0' );
		numb.b <<= 1;
	}
	putchar('\n');

	return 0;
}
