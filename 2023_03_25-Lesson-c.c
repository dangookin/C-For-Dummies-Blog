#include <stdio.h>
#include <time.h>

int main()
{
	long delay;

	/* pause one second */
	for( delay=0; delay<377291420; delay ++ )
		time(NULL);

	return(0);
}
