#include <stdio.h>
#include <math.h>

int main()
{
	/* phone numbers for this example have ten digits */
	const int digits = 10;
	const int open_paren = 10;
	const int close_paren = 7;
	const int dash = 4;
	long phone,p;
	int x,d;

	/* assign phone number as a long value */
	phone = 5551234001;

	/* process the phone number */
	for( x=digits; x>0; x-- )
	{
		/* extract each digit, left-to-right */
		p = (long)pow(10,x);
		d = (phone % p)/(p/10);

		/* output the formatting phone number */
		switch(x)
		{
			case open_paren:
				printf("(%d",d);
				break;
			case close_paren:
				printf(") %d",d);
				break;
			case dash:
				printf("-%d",d);
				break;
			default:
				printf("%d",d);
		}
	}
	putchar('\n');

	return 0;
}
