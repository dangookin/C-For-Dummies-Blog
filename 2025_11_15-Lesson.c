#include <stdio.h>

int binary(char *v)
{
	int b,x,digit;

	b = 0;
	for( x=0; x<4; x++ )
	{
		b<<=1;
		digit = *v-'0';
		if( digit==0 || digit==1 )
			b+=digit;
		else
			return(-1);
		v++;
	}

	return(b);
}

int main()
{
	int month,d,b;
	int days[12] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	char date[5];

	for( month=0; month<12; month++ )
	{
		for( d=0; d<days[month]; d++ )
		{
			snprintf(date,5,"%02d%02d",
					month+1,
					d+1
				  );
			b = binary(date);
			if( b != -1 )
				printf("%s = %X\n",date,b);
		}
	}

	return 0;
}
