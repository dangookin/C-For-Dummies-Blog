#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
	int x,r;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* set the locale for wide characters */
	setlocale(LC_ALL,"");

	/* generate and evaluate 20 random chars */
	for( x=0; x<200; x++ )
	{
		r = rand() % 0xFF;	/* char range */
		wprintf(L"%03d %02X ",r,r);
		if( isascii(r) )
		{
			if( iscntrl(r) )
			{
				/* call out DEL */
				if( r==127 )
					wprintf(L"%lc - control code",9249);
				/* other Unicode ctrl chars */
				else
					wprintf(L"%lc - control code",r+9216);
			}
			else
				wprintf(L"%lc - ASCII",r);
		}
		else
		{
			wprintf(L"%lc - non-ASCII",0xB7);	/* B7 = dot */
		}
		putwchar(L'\n');
	}

	return 0;
}
