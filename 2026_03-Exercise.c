#include <stdio.h>

int main()
{
	int a,b,c,d,max;

	max = 0;
	for( a=0; a<36; a++ )
		for( b=0; b<36; b++ )
			for( c=0; c<36; c++ )
				for( d=0; d<36; d++ )
					if( a+b+c+d == 36 )
						if( (a*b)+(b*c)+(c*d) > max )
							max = (a*b)+(b*c)+(c*d);
	printf("%d\n",max);

	return 0;
}
