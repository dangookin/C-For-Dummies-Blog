#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int kbhit(void)
{
	int k;

	ioctl(STDIN_FILENO,FIONREAD,&k);

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
