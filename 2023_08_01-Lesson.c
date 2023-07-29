#include <stdio.h>

int main()
{
	const int count = 7;
	char *variable[] = {
		"readInputMeter",
		"cyclical_redundancy_check",
		"bumpyRide",
		"search_for_node",
		"string_convert",
		"divideByZeroError",
		"giveUpAndExplode"
	};
	int x;

	for(x=0; x<count; x++ )
	{
		printf("%s\n",variable[x]);
	}

	return(0);
}
