#include <stdio.h>

int main()
{
	int month,d;
	int days[12] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	for( month=0; month<12; month++ )
	{
		for( d=0; d<days[month]; d++ )
			printf("%02d%02d\n",
					month+1,
					d+1
				  );
	}

	return 0;
}
