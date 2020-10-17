#include <stdio.h>

void str_toupper(char *s)
{
	while(*s)
	{
		if( *s>='a' && *s<='z' )
			*s &= 223;
		s++;
	}
}

int main()
{
	char sample[] = "This is Sample String #1 TEXT\n";

	printf("Before:\n%s",sample);
	str_toupper(sample);
	printf("After:\n%s",sample);

	return(0);
}
