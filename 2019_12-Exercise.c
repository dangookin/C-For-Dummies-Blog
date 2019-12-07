#include <stdio.h>
#include <ctype.h>

void toMorse(char c)
{
	char *morse_alpha[] = {
		".-", "-...", "-.-.", "-..", ".", "..-.",
		"--.", "....", "..", ".---", "-.-", ".-..",
		"--", "-.", "---", ".--.", "--.-", ".-.",
		"...", "-", "..-", "...-", ".--", "-..-",
		"-.--", "--.."
	};
	char *morse_digit[] = {
		"-----", ".----", "..---", "...--", "....-",
		".....", "-....", "--...", "---..", "----."
	};
	int m;

	if( isalpha(c) )
	{
		/* Morse is case-insensitive */
		c = toupper(c);
		m = c - 'A';
		printf("%s ",morse_alpha[m]);
	}
	else if( isdigit(c) )
	{
		m = c - '0';
		printf("%s ",morse_digit[m]);
	}
	else if( c==' ' || c=='\n' )
	{
		putchar('\n');
	}
	else
		return;
}

int main()
{
	int ch;

	while(1)
	{
		ch = getc(stdin);
		if( ch==EOF )
			break;
		toMorse(ch);
	}

	return(0);
}
