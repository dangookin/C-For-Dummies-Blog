#include <stdio.h>
#include <unistd.h>

int main()
{
	char prompt[] = "Type away: ";
	char buffer[BUFSIZ];
	int ch,offset;

	/* output the prompt */
	write(fileno(stdout),prompt,sizeof(prompt));

	/* read standard input until the newline */
	offset = 0;
	do
	{
		read(fileno(stdin),&ch,1);
		buffer[offset] = ch;
		offset++;
		/* test for overflow */
		if( offset>BUFSIZ )
			break;
	}
	while( ch!='\n' );

	/* output the buffer */
	write(fileno(stdout),buffer,offset);

	/* clean-up */
	return 0;
}
