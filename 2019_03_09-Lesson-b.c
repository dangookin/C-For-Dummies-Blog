#include <stdio.h>

int main()
{
	char format0[32];
	char format1[] = "My name is %s";
	char format2[] = " %s\n";

	sprintf(format0,"%s%s",format1,format2);
	printf(format0,"Dan","Gookin");

	return(0);
}

