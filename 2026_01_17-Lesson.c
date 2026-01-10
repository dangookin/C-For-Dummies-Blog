#include <stdio.h>
#include <termios.h>

/* read input and write output */
void in_out(void)
{
	int x;
	char buffer[BUFSIZ];

	printf("Type some text: ");
	/* read input */
	fgets(buffer,BUFSIZ,stdin);

	/* send output */
	printf("Buffer: ");
	for( x=0; buffer[x]; x++ )
		printf("%02X ",buffer[x]);
	putchar('\n');
}

int main()
{
	struct termios original,raw;

	/* first read stdin cooked */
	puts("Cooked mode on");
	in_out();

	/* disable cannonical terminal mode */
	tcgetattr(fileno(stdin),&original);
	raw = original;
	raw.c_lflag = raw.c_lflag ^ ICANON;
	tcsetattr(fileno(stdin),TCSANOW,&raw);

	/* read stdin raw */
	puts("Raw mode on");
	in_out();

	/* restore and clean-up */
	tcsetattr(fileno(stdin),TCSANOW,&original);
	return 0;
}
