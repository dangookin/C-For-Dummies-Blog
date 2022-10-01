#include <gmp.h>

int main()
{
	mpz_t i;
	mpz_init(i);

	/* i equals one billion */
	mpz_set_ui(i,1000000000);
	gmp_printf("%Zd\n",i);

	return(0);
}
