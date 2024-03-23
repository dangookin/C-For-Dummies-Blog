#include <stdio.h>
#include <sys/ioctl.h>

int kbhit(void)
{
	int k;

	ioctl(0,FIONREAD,&k);

	return(k);
}

int main()
{
	char a;

	a = 'A';
	while(1)
	{
		printf(" %c",a++);
		if( a=='Z' )
			a = 'A';
		/* terminate on key */
		if( kbhit() )
		{
			getchar();
			break;
		}
	}

	return 0;
}
