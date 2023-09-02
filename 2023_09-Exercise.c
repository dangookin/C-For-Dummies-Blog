#include <stdio.h>

int charcount(char *s,char c)
{
	int total = 0;

	while(*s)
	{
		if( *s==c )
			total++;
		s++;
	}

	return(total);
}

int main()
{
	const int size = 64;
	char buffer[size];
	char c,t;

	printf("Enter a string: ");
	fgets(buffer,size,stdin);
	printf("Enter a character to find: ");
	scanf("%c",&c);

	t = charcount(buffer,c);
	printf("There are %d letters '%c' in: %s",
			t,
			c,
			buffer
		  );

	return(0);
}
