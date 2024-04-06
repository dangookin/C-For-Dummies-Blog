#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>

#define MAX_EVENTS 5

int main() {
	char a = 'A';
    int x,fd,nfds;
    struct epoll_event evin,events[MAX_EVENTS];

    /* Create an epoll instance */
    fd = epoll_create1(0);
    if (fd == -1)
	{
        perror("epoll_create1");
        return 1;
    }

    /* add input event for standard input */
    evin.events = EPOLLIN;
    evin.data.fd = STDIN_FILENO;
    if (epoll_ctl(fd, EPOLL_CTL_ADD, STDIN_FILENO, &evin) == -1)
	{
        perror("epoll_ctl");
        return 1;
    }

	/* endless loop to scan for keyboard activity */
    while (1) {
		/* output the alphabet loop */
		printf(" %c",a++);
		if( a=='Z' )
			a = 'A';

		/* obtain number of file desciptors */
        nfds = epoll_wait(fd, events, MAX_EVENTS, 0);
        if (nfds == -1)
		{
            perror("epoll_wait");
            return 1;
        }

		/* scan file descriptors */
		for ( x=0; x<nfds; x++)
		{
			/* keyboard input buffer full */
            if ( events[x].data.fd==STDIN_FILENO )
			{
				getchar();
				return 0;
            }
        }
    }

    return 0;
}
