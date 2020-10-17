#include <stdio.h>

void str_toinverse(char *s)
{
	while(*s)
	{
		if( *s>='A' && *s<='Z' )
		{
			*s |= 32;
			s++;
		}
		else if( *s>='a' && *s<='z' )
		{
			*s &= 223;
			s++;
		}
		else
			s++;
	}
}

int main()
{
	char sample[] = "This is Sample String #1 TEXT\n";

	printf("Before:\n%s",sample);
	str_toinverse(sample);
	printf("After:\n%s",sample);

	return(0);
}
