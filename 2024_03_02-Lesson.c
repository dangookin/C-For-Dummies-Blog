#include <stdio.h>

int main()
{
	int a;

	printf("1, 2, 3: ");
	scanf("%d",&a);

	switch(a)
	{
		case 1:
			puts("One!");
			break;
		default:
			puts("You bad!");
			break;
		case 2:
			puts("Two!");
			break;
		case 3:
			puts("Three!");
			break;
	}

	return 0;
}
