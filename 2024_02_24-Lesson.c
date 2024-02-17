#include <stdio.h>

int main()
{
	const int two = 2;
	int a;

	printf("1, 2, 3: ");
	scanf("%d",&a);

	switch(a)
	{
		case 1:
			puts("One!");
			break;
		case two:
			puts("Two!");
			break;
		case 3:
			puts("Three!");
			break;
		default:
			puts("You bad!");
	}

	return 0;
}
