#include <stdio.h>

void str_tolower(char *s)
{
	while(*s)
	{
		if( *s>='A' && *s<='Z' )
			*s |= 32;
		s++;
	}
}

int main()
{
	char sample[] = "This is Sample String #1 TEXT\n";

	printf("Before:\n%s",sample);
	str_tolower(sample);
	printf("After:\n%s",sample);

	return(0);
}
