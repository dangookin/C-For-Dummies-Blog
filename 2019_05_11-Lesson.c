#include <stdio.h>

#define SIZE 32

int main()
{
	char input[SIZE];
	signed int x,ch;

	printf("Text: ");
	fgets(input,SIZE,stdin);

	x = 0;
	printf("Translation:\n%d",input[x]);
	while( (ch = input[x]) )
	{
		if( ch == '\n' )
			break;
		x++;
		printf(", %d",input[x] - ch);
	}
	printf("\nCount: %d\n",x+1);
	
	return(0);
}

