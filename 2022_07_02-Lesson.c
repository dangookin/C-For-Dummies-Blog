#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *patiently(void *p)
{
	int fd;
	char buffer[BUFSIZ];

	fd = *(int *)p;

	while( read(fd,buffer,BUFSIZ) == 0 )
		sleep(1);
	printf("The thread has received: %s",buffer);

	return(NULL);
}

int main()
{
	char buffer[BUFSIZ];
	int fp[2];
	pthread_t thd;
	int r;

	/* open the pipe */
	r = pipe(fp);
	if( r==-1 )
	{
		perror("Pipe");
		exit(1);
	}

	/* spawn the thread, passing it the read
	   end of the pipe */
	r = pthread_create( &thd, NULL, patiently, (void *)&fp[0] );
	if( r!=0 )
	{
		perror("Thread");
		exit(1);
	}

	/* interact with the thread */
	printf("Send some text to the thread: ");
	fgets(buffer,BUFSIZ,stdin);
	write(fp[1],buffer,strlen(buffer));

	puts("Press Enter:");
	getchar();

	return(0);
}
