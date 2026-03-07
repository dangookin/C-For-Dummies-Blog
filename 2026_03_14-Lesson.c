#include <locale.h>
#include <wchar.h>

#define PI_CHAR 0x03c0
#define ACCURACY 500000

int main()
{
	float pi = 0.0;
	int loop,denominator,sign;

	/* use Leibniz formula to calculate pi */
	denominator = 1;
   	sign = 0;
	for( loop=0; loop<ACCURACY; loop++ )
	{
		pi += (sign%2?-1:1) * 4.0/denominator;
		denominator+=2;
		sign++;
	}
	
	/* output wide character 'pi' */
	setlocale(LC_ALL,"");
	wprintf(L"%lc = %.5f\n",PI_CHAR,pi);

	/* clean-up */
	return 0;
}
