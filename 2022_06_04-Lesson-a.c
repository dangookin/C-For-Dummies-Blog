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
		printf("%s\n",(char *)a);
		sleep(1);
	}

	return(NULL);
}

int main()
{
	char buffer[BUFSIZ];
	int r;
	pthread_t thd1,thd2;

	/* spawn the thread 1 */
	r = pthread_create( &thd1, NULL, thread_funct, "*");
	if( r!=0 )
	{
		perror("Thread");
		exit(1);
	}
	
	/* spawn the thread 2 */
	r = pthread_create( &thd2, NULL, thread_funct, "#");
	if( r!=0 )
	{
		perror("Thread");
		exit(1);
	}
	
	/* prompt for your name */
	printf("What is your name? ");
	fgets(buffer,BUFSIZ,stdin);
	printf("Hello, %s",buffer);

	return(0);
}
