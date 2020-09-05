#include <stdio.h>

int main()
{
	char name[16];
	int score;

	printf("Enter your name and score: ");
	scanf("%s %d",name,&score);
	printf("%s scored %d\n",name,score);

	return(0);
}
