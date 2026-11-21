#include <stdio.h>
#include <stdlib.h>

/* output binary representation of the fraction */
void binout(unsigned b)
{
	int x,exponent;

	/* extract exponent */
	exponent = b & 0x7F800000;
	exponent >>= 23;
	/* undo the standard bias of 127 */
	exponent -= 127;
	/* mask out the sign and exponent */
	b &= 0x007FFFFF;
	/* add the "assumed" leading bit */
	b |= 0x00800000;

	/* output binary decimal */
	printf("binary32: 0.");
	for( x=0; x<32; x++ )
	{
		/* account for exponent shift, max 9 places */
		if( x>=9+exponent )
			putchar( b & 0x80000000 ? '1' : '0' );
		b <<= 1;
	}
	putchar('\n');
}

int main()
{
	union real {
		float f;
		unsigned long l;
	} numb;
	unsigned long save;
	char binary[33];
	int x;

	/* gather input */
	printf("Enter a positive decimal: ");
	scanf("%f",&numb.f);
	if( numb.f>=1.0 )
	{
		puts("Enter a value between 0.0 to 1.0");
		return(-1);
	}

	/* retain original value */
	save = numb.l;

	/* process fraction */
	printf("input: %f\n",numb.f);
	for( x=0; x<32; x++ )
	{
		numb.f *= 2.0;
		printf("x2 = %f\n",numb.f);
		if( numb.f==0 )
			break;
		if( numb.f>=1.0 )
		{
			binary[x] = '1';
			numb.f -= 1.0;
		}
		else
			binary[x] = '0';
	}
	binary[x] = '\0';		/* terminate string */
	printf(" extract: 0.%s\n",binary);
	binout(save);

	/* clean-up */
	return 0;
}
