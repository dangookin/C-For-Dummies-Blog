#include <stdio.h>

#define BASE36_MAX 36

/* output a base 36 value */
char base36_output(int v)
{
	if( v<10 )
		return( v+'0' );
	else if( v<BASE36_MAX )
		return( v+'A'-10 );
	else
		return('\0');
}

int main()
{
	int x;

	puts("Decimal - Base 36");
	for( x=0; x<BASE36_MAX; x++ )
		printf("%2d\t%c\n",x,base36_output(x) );

	return 0;
}
