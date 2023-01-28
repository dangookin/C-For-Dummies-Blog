#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main()
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	printf("This terminal window is %d rows by %d columns\n",
			w.ws_row,
			w.ws_col
		  );

	return(0);
}
