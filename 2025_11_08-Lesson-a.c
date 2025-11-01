#include <stdio.h>

int main()
{
	int month,d,offset;
	int days[12] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	char date[365][5];

	/* calculate and store dates */
	offset = 0;
	for( month=0; month<12; month++ )
	{
		for( d=0; d<days[month]; d++ )
		{
			snprintf(date[offset],5,"%02d%02d",
					month+1,
					d+1
				  );
			offset++;
		}
	}

	/* output all dates */
	for(offset=0; offset<365; offset++)
		printf("%s\n",date[offset]);

	return 0;
}
