#include <locale.h>
#include <wchar.h>
#include <ctype.h>

int main()
{
	int ch;
	
	/* set locale for wide characters */
	setlocale(LC_ALL,"");

	/* output the lower ASCII codes */
	for( ch=0x00; ch<=' '; ch++ )
	{
		wprintf(L"%2d %02X %lc is",ch,ch,ch+9216);
		if( isspace(ch) )
		{
			wprintf(L" space");
			if( isblank(ch) )
				wprintf(L" and blank");
		}
		else
		{
			wprintf(L" non-space/blank");
		}
		putwchar(L'\n');
	}

	return 0;
}
