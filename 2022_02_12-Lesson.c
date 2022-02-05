#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t p;
	int stat;

	/* split this program into two processes */
	p = fork();
	
	if( p==0 )		/* child process is running */
	{
		execl("twelve",NULL);
	}
	else			/* parent process is running */
	{
		wait(&stat);				/* wait for the child */
		if( WIFEXITED(stat))		/* examine exit status */
			printf("Child process exit status = %d\n",WEXITSTATUS(stat));
		else
			printf("Unable to locate exit status\n");
	}

	return(0);
}
