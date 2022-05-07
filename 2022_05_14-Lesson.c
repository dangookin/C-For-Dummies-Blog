#include <stdio.h>

char *decimal(float a)
{
	const int size=32;
	static char buffer[size];		/* more than enough room */
	int offset,base;

	snprintf(buffer,size,"%f",a);
	offset = base = 0;
		/* first, locate the decimal */
	while( buffer[offset]!='.' )
	{
		offset++;
	}
		/* copy the characters to the front */
	offset++;		/* skip over the decimal */
	while( buffer[offset] )
	{
		buffer[base] = buffer[offset];
		offset++;
		base++;
	}
	buffer[base] = '\0';	/* cap the string */

	return(buffer);
}

int main()
{
	float a;

	printf("Enter a decimal value: ");
	scanf("%f",&a);

	printf("Decimal portion is: %s\n",decimal(a));

	return(0);
}
