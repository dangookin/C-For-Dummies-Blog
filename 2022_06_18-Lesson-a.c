#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *eternal(void *p)
{
	for( ;; )
	{
		printf("On I go...\n");
		sleep(1);
	}
}

int main()
{
	pthread_t thd;
	int r;

	puts("Launching endless thread...");
	/* spawn the new thread */
	r = pthread_create( &thd, NULL, eternal, NULL);
	if( r!=0 )
	{
		perror("Thread");
		exit(1);
	}
	
	puts("Press Enter just because");
	getchar();

	puts("Press Enter to quit");
	getchar();

	return(0);
}
