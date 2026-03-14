/* compile with `-lm` to link in the math library */
#include <locale.h>
#include <wchar.h>
#include <math.h>

#define PI_CHAR 0x03c0
#define ACCURACY 1800000

int main()
{
	unsigned long x;
	double total;

	/* use the Basel Problem to solve for pi */
	total = 0.0;
	for( x=1; x<=ACCURACY; x++ )
	{
		total += 1.0/(x*x);
	}

	/* output wide character 'pi' */
	setlocale(LC_ALL,"");
	wprintf(L"%lc = %f\n",PI_CHAR,sqrt(total*6.0) );

	return 0;
}
