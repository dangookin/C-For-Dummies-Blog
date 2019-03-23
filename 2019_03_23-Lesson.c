#include <stdio.h>
#include <locale.h>

int main()
{
	char *old;

	old = setlocale(LC_ALL,"");
	printf("Old locale setting: %s\n",old);

	return(0);
}
