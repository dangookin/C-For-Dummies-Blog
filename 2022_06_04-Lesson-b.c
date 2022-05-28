#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_funct(void *a)
{
	const int loop=8;
	int x;

	for( x=0; x<loop; x++ )
	{
		printf("*\n");
		sleep(1);
	}

	return(NULL);
}

int main()
{
	char buffer[BUFSIZ];
	int r;
	pthread_t thd;

	/* spawn the new thread */
	r = pthread_create( &thd, NULL, thread_funct, NULL);
	if( r!=0 )
	{
		perror("Thread");
		exit(1);
	}
	
	/* wait for the thread */
	r = pthread_join( thd, NULL );
	if( r!=0 )
	{
		perror("Thread join");
		exit(1);
	}

	/* prompt for your name */
	printf("What is your name? ");
	fgets(buffer,BUFSIZ,stdin);
	printf("Hello, %s",buffer);

	return(0);
}
