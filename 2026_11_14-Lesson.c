#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;
	float f;

	/* gather input */
	printf("Enter a positive decimal: ");
	scanf("%f",&f);
	if( f>=1.0)
	{
		puts("Enter a value 0.0 to 1.0");
		return(-1);
	}

	/* process fraction */
	printf("0.");
	for( x=0; x<16; x++ )
	{
		f *= 2.0;
		if( f==0 )
			break;
		if( f>=1.0 )
		{
			putchar('1');
			f -= 1.0;
		}
		else
			putchar('0');
	}
	putchar('\n');

	/* clean-up */
	return 0;
}
