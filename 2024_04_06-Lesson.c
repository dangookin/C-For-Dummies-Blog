#include <stdio.h>
#include <sys/time.h>
#include <sys/select.h>

int main()
{
	char a;
	fd_set keyread;
	struct timeval timeout;
	int r;

	/* preset values */
	a = 'A';
	timeout.tv_sec = 0;		/* timeout structure */
	timeout.tv_usec = 0;

	/* loop until keyboard input available */
	while(1)
	{
		/* initailize file descriptor set */
		FD_ZERO(&keyread);
		FD_SET(0,&keyread);
		/* check standard input status */
		r = select(1,&keyread,NULL,NULL,&timeout);
		if( r==-1 )
		{
			perror("select");
			return 1;
		}

		/* output the alphabet loop */
		printf(" %c",a++);
		if( a=='Z' )
			a = 'A';
		/* terminate on keyboard input */
		if( r>0 )
		{
			/* confirm that it's standard input */
			if( FD_ISSET(0,&keyread) )
			{
				getchar();
				break;
			}
		}
	}

	return 0;
}
