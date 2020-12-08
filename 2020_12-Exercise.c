#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void error_exit(void)
{
	puts("Invalid input");
	exit(1);
}

int main()
{
	float w;
	char input[16];
	char *r,*convert;

	/* intro text */
	puts("Type a value to convert, suffixed by conversion types:");
	puts("K - kilos, P - pounds, S - stones");
	puts("Example: 2.0PK (convert 2.0 pounds to kilograms)");
	printf("Convert: ");

	/* gather input */
	r = fgets(input,16,stdin);
	if( r==NULL )
		error_exit();

	/* process input */
	w = strtof(input,&convert);
		/* text for nothing input */
	if( w==0.0 && convert==input )
		error_exit();
		/* confirm that conversion characters exist */
	if( *convert=='\0' ||
		*convert=='\n' ||
		*(convert+1)=='\0' ||
		*(convert+1)=='\n')
	{
		error_exit();
	}
		/* kilo conversions */
	if( toupper(*convert)=='K' )
	{
		if( toupper( *(convert+1))=='P' )
			printf("%.2f kilos is %.2f pounds\n",w,w*2.20462);
		else if( toupper( *(convert+1))=='S' )
			printf("%.2f kilos is %.2f stone\n",w,w*0.157473);
		else
			error_exit();
	}
		/* pounds conversions */
	else if( toupper(*convert)=='P' )
	{
		if( toupper( *(convert+1))=='K' )
			printf("%.2f pounds is %.2f kilos\n",w,w*0.453592);
		else if( toupper( *(convert+1))=='S' )
			printf("%.2f pounds is %.2f stone\n",w,w*0.0714286);
		else
			error_exit();
	}
		/* stone conversions */
	else if( toupper(*convert)=='S' )
	{
		if( toupper( *(convert+1))=='K' )
			printf("%.2f stone is %.2f kilos\n",w,w*6.35029);
		else if( toupper( *(convert+1))=='P' )
			printf("%.2f stone is %.2f pounds\n",w,w*14.0);
		else
			error_exit();
	}
	else
		error_exit();

	return(0);
}
