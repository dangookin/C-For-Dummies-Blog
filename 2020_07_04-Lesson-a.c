#include <stdio.h>

int main()
{
	printf("char is %lu bits\n",sizeof(char)*8);
	printf("short is %lu bits\n",sizeof(short)*8);
	printf("int is %lu bits\n",sizeof(int)*8);
	printf("long is %lu bits\n",sizeof(long)*8);
	printf("long long is %lu bits\n",sizeof(long long)*8);

	return(0);
}
