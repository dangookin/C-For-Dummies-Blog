#include <stdio.h>

int main()
{
	float input,fractional;
	int integer;

	printf("Enter a decimal value: ");
	scanf("%f",&input);

	/* magic happens here */

	printf("Value %f can be split in to %d and %f\n",
			input,integer,fractional
		  );

	return(0);
}
