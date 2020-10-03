#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *term;
	FILE *tout;

	/* obtain terminal name and open */
	term = ttyname(0);
	tout = fopen(term,"w");
	if( tout==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",term);
		exit(1);
	}

	/* send text to the terminal */
	fprintf(tout,"Hello, terminal %s\n",term);

	/* close */
	fclose(tout);

	return(0);
}
