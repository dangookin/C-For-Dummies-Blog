#include <stdio.h>
#include <sys/resource.h>

int main()
{
	struct rlimit limit;
	int r;

	r = getrlimit( RLIMIT_DATA, &limit );
	if( r==-1 )
	{
		fprintf(stderr,"Some kinda error\n");
		return(1);
	}

	printf("Current soft limit on data is %llu\n",
			limit.rlim_cur
		  );
	printf("Current hard limit on data is %llu\n",
			limit.rlim_max
		  );
	
	return(0);
}

