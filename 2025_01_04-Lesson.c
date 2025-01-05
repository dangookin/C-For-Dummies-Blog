#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char *concatenate(int v, ...)
{
	va_list argc;
	int x;
	char *r,*temp;

	va_start(argc,v);
	for(x=0; x<v; x++)
	{
		temp = va_arg(argc,char *);
		if( x==0 )
		{
			r = malloc( sizeof(char) * strlen(temp) +1 );
			if( r==NULL )
				return("NULL");
			strcpy(r,temp);
		}
		else
		{
			r = realloc(r, sizeof(char) * (strlen(r) + strlen(temp)) +1 );
			if( r==NULL )
				return("NULL");
			strcat(r,temp);
		}
	}

	/* clean up */
	va_end(argc);
	return(r);
}

int main()
{
	char *a,*b,*c;

	a = concatenate(4,"alpha ","beta ","gamma ","delta");
	printf("%s\n",a);

	b = concatenate(1,"Hello, world!");
	printf("%s\n",b);

	c = concatenate(6,"f","o","o","b","a","r");
	printf("%s\n",c);

	/* clean-up */
	free(a);
	free(b);
	free(c);
	return 0;
}
