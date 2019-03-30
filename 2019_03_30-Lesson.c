#include <stdio.h>
#include <locale.h>

int main()
{
	struct lconv *locale_ptr;

	locale_ptr = localeconv();

	printf("Decimal point: %s\n",locale_ptr->decimal_point);
	printf("Thousands separator: %s\n",locale_ptr->thousands_sep);
	printf("Currency symbol: %s\n",locale_ptr->currency_symbol);

	return(0);
}
