#include <stdio.h>
#include <stdlib.h>

/* create a 32-character string from a
   long int value */
char *binString(long a)
{
	char *bin;
	int x;

	/* allocate string storage */
	bin = malloc(sizeof(char) * 33);
	if( bin==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* create binary string */
	for(x=0; x<32; x++ )
	{
		*(bin+x) = a & 0x80000000 ? '1' : '0';
		a <<= 1;
	}
	*(bin+x) = '\0';

	return(bin);
}

int main()
{
	union real {
		float f;
		long l;
	} numb;
	unsigned signbit,exponent,mantissa;

	/* gather input */
	printf("Enter a value: ");
	scanf("%f",&numb.f);

	/* output the full binary value */
	printf("Integer value is %ld\n",numb.l);
	printf("Binary value is %s\n",binString(numb.l));

	/* output integer values - sign bit */
	signbit = numb.l & 0x80000000;
	signbit >>= 31;
	printf("Sign bit is 0x%X\n",signbit);
	/* exponent */
	exponent = numb.l & 0x7F800000;
	exponent >>= 23;
	printf("Exponent is 0x%X\n",exponent);
	/* fraction */
	mantissa = numb.l & 0x00EFFFFF;
	printf("Fraction is 0x%X\n",mantissa);

	return 0;
}
