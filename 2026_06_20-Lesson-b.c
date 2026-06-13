#include <locale.h>
#include <wchar.h>
#include <stdbool.h>

/* is the character a control code? */
int iscntrl(int c)
{
    if( (c>=0 && c<=31) || c==127 )
        return true;
    else
        return false;
}

/* is the character "punctuation"? */
int ispunct(int c)
{
	/* eliminate control codes & space */
	if( c>=0 && c<=' ')
		return false;
	/* eliminate numbers/digits */
	if( c>='0' && c<='9' )
		return false;
	/* eliminate uppercase */
	if( c>='A' && c<='Z' )
		return false;
	/* eliminate lowercase */
	if( c>='a' && c<='z' )
		return false;
	/* eliminate DEL */
	if( c==127 )
		return false;

	return true;
}

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
