#include <stdio.h>

int main()
{
	long d;
	int x,l;
	long value[10] = {
		1, 12, 123, 1234, 12345,
		123456, 1234567, 12345678,
		123456789, 1234567890
	};

	for( x=0; x<10; x++ )
	{
		l=d=1;
		while( d<=10000000000 )
		{
			if( value[x]<d )
			{
				printf("%ld is %d digits long\n",value[x],l-1);
				break;
			}
			d*=10;
			l++;
		}
	}

	return(0);
}
