#include <stdio.h>
#include <wchar.h>
#include <locale.h>

/* convert Greek lowercase to uppercase */
wchar_t toGupper(wchar_t c)
{
	if( c>=0x03B1 && c<=0x03C9 )
		return( c-0x20 );
	return(c);
}

/* convert Greek uppercase to lowercase */
wchar_t toGlower(wchar_t c)
{
	if( c>=0x0391 && c<=0x03A9 )
		return( c+0x20 );
	return(c);
}

int main()
{
	int x;
	wchar_t phrase[] = L"Ξεσκεπαζω την Ψυχοφθορα Βδελυγμια";

	/* set the locale */
	setlocale(LC_ALL,"");

	/* output original phrase */
	wprintf(L"Original:\n");
	x = 0;
	while(phrase[x])
	{
		putwchar(phrase[x]);
		x++;
	}
	putwchar(L'\n');
	
	/* output all caps (GREEK) */
	wprintf(L"ALL CAPS:\n");
	x = 0;
	while(phrase[x])
	{
		putwchar(toGupper(phrase[x]));
		x++;
	}
	putwchar(L'\n');
	
	/* output lowercase (GREEK) */
	wprintf(L"lowercase:\n");
	x = 0;
	while(phrase[x])
	{
		putwchar(toGlower(phrase[x]));
		x++;
	}
	putwchar(L'\n');
	
	return 0;
}
