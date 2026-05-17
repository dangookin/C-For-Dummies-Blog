#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define DEL 127

int isalpha(int c)
{
	if( (c>='A' && c<='Z') || (c>='a' && c<='z') )
			return TRUE;
	return FALSE;
}

int isdigit(int c)
{
	if( c>='0' && c<='9' )
		return TRUE;
	return FALSE;
}

int isalnum(int c)
{
	if( isalpha(c) || isdigit(c) )
		return TRUE;
	return FALSE;
}

int main()
{
	int ch;

	for( ch=' '; ch<=DEL; ch++ )
	{
		printf("%3d %2X '%c' is",ch,ch,ch);
		if( isalnum(ch) )
		{
			printf(" alphanumeric");
			if( isalpha(ch) )
				printf(" (alphabetic)");
			if( isdigit(ch) )
				printf(" (digit)");
		}
		else
		{
			printf(" non-alphanumeric");
		}
		putchar('\n');
	}

	return 0;
}
