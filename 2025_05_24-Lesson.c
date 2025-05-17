#include <stdio.h>

int main()
{
	int sides,degrees;

	printf("Sides\tAngles\tTotal (degrees)\n");
	for(sides = 3; sides<=12; sides++ )
	{
		degrees = (sides - 2) * 180;
		printf("%5d\t%6d\t%5d\n",
				sides,
				degrees/sides,
				degrees
			  );
	}

	return 0;
}
