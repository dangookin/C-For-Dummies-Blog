#include <gmp.h>

int main()
{
	mpz_t a,b,x;

	/* initialize */
	mpz_init(a);
	mpz_init(b);
	mpz_init(x);

	/* set values */
	mpz_set_ui(a,3000000000);	/* three billion */
	mpz_set_ui(b,5000000000);	/* five billion */

	/* add the values */
	mpz_add(x,a,b);
	/* output */
	gmp_printf("%Zd + %Zd = %Zd\n",a,b,x);

	/* multiply */
	mpz_init(x);
	mpz_addmul(x,a,b);
	/* output */
	gmp_printf("%Zd * %Zd = %Zd\n",a,b,x);

	return(0);
}
