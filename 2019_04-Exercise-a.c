#include <stdio.h>

int interesting(int v)
{
	char buffer[4];

	sprintf(buffer,"%d",v);

	if( buffer[0]==buffer[1] && buffer[1]==buffer[2] )
		return(1);
	else
		return(0);
}

int main()
{
	int x;

	for(x=100;x<1000;x++)
	{
		if( interesting(x) )
			printf("%d is interesting\n",x);
	}

	return(0);
}

