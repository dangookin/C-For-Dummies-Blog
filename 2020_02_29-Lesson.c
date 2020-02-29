#include <stdio.h>
#include <termios.h>

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif /* STDIN_FILENO */

#define SIZE 16

int main()
{
	struct termios original,noecho;
	char buffer[SIZE];
	int x;

	/* obtain the current terminal configuration */
	tcgetattr(STDIN_FILENO,&original);
	/* duplicate it */
	noecho = original;
	/* turn off full duplex */
	noecho.c_lflag = noecho.c_lflag ^ ECHO;
	/* set the terminal */
	tcsetattr(STDIN_FILENO, TCSANOW, &noecho);

	/* prompt for and input the password */
	printf("Password: ");
	fgets(buffer,SIZE,stdin);
	/* remove newline */
	for( x=0; x<SIZE; x++)
	{
		if( buffer[x]=='\n' )
		{
			buffer[x]='\0';
			break;
		}
	}
	putchar('\n');

	/* restore the terminal settings */
	tcsetattr(STDIN_FILENO, TCSANOW, &original);
	/* output the result */
	printf("Your password is '%s'\n",buffer);

	return(0);
}
