#include <locale.h>
#include <wchar.h>
#include <stdbool.h>

#define TAB 0x09
#define LF 0x0A
#define VT 0x0B
#define FF 0x0C
#define CR 0x0D
#define SPACE 0x20

/* returns true for all whitespace chars */
int isspace(int c)
{
	switch(c)
	{
		case TAB:
		case LF:
		case VT:
		case FF:
		case CR:
		case SPACE:
			return true;
		default:
			return false;
	}
}

/* returns true for tab and space only */
int isblank(int c)
{
	if( c==TAB || c==SPACE )
		return true;
	else
		return false;
}

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
