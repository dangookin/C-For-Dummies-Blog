#include <locale.h>
#include <wchar.h>
#include <ctype.h>

/* output the wide ASCII character
   specifically the control codes */
void outwide(int c)
{
	if( iscntrl(c) )
	{
		if( c==127 )
			putwchar(9249);	/* DEL */
		else
			/* 9216 = control code chars */
			putwchar(c+9216);
	}
	else
	{
		putwchar(c);
	}
}

int main()
{
	int ch;

	/* set the locale for wide characters */
	setlocale(LC_ALL,"");

	wprintf(L"Punctuation characters:\n");
	/* ASCII range */
	for( ch=0; ch<=127; ch++ )
		if( ispunct(ch) )
			outwide(ch);
	putwchar(L'\n');

	wprintf(L"Not punctuation characters:\n");
	/* ASCII range */
	for( ch=0; ch<=127; ch++ )
		if( !ispunct(ch) )
			outwide(ch);
	putwchar(L'\n');

	return 0;
}
