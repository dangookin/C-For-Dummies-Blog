#include <stdio.h>

#define RED "\e[41m"
#define WHITE "\e[47m"
#define BLUE "\e[37;44m"
#define NORMAL "\e[m"
#define LONG 35
#define SHORT 22

void bar(char *color,int size)
{
	printf("%s",color);

	while(size--)
		putchar(' ');
	printf("%s\n",NORMAL);
}

int main()
{
	int star,stripe,count;

	for( stripe=0,star=0; stripe<13; stripe++ )
	{
		printf("%s",BLUE);
		if( stripe<7 )
		{
			for(count=0;count<SHORT;count++,star++)
				!(star%4) ? putchar('*') : putchar(' ');
			stripe%2 ? bar(WHITE,LONG) : bar(RED,LONG);
		}
		else
		{
			stripe%2 ? bar(WHITE,LONG+SHORT) : bar(RED,LONG+SHORT);
		}
	}

	return 0;
}
