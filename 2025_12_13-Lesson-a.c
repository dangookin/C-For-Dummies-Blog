#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#define RED "\e[31m"
#define NORMAL "\e[m"

int main()
{
	wchar_t chw;

	/* set the local for wide characters */
	setlocale(LC_CTYPE,"UTF-8");

	for( chw=0; chw<=127; chw++ )
	{
		wprintf(L"%02X %03d ",chw,chw);
		if( chw<32 )
			wprintf(L"%s%lc%s",RED,chw+9216,NORMAL);
		else if( chw==127 )
			wprintf(L"%s%lc%s",RED,9249,NORMAL);
		else
			putwchar(chw);
		putwchar(L'\n');
	}
	return 0;
}
