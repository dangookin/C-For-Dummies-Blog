#include <stdio.h>

void recurse(int i)
{
	printf("%d\n",i);
	recurse(i+1);
}

int main()
{
	recurse(0);

	return 0;
}
