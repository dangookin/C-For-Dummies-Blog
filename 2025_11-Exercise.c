#include <stdio.h>

int main()
{
	int a = 0;
	char b = 'A';

output:
	if( a==10 ) goto end;
	printf("%c%d  ",b,a);
	b++;
	if( b=='K' )
	{
		putchar('\n');
		a++;
		b='A';
	}
	goto output;

end:
	return 0;
}
