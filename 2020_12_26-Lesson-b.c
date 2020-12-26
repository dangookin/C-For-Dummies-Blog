#include <stdio.h>

int main()
{
	char c[] = { 'a', 'b', 'c', 'd' };
	int i[] = { 10, 100 };
	float f[] = { 1.4, 5.7, 9.0, 22.7, 88.8 };
	char *s[3] = { "this", "that", "the other" };

	puts("Array element count:");
	printf("c = %lu\n",sizeof(c)/sizeof(c[0]) );
	printf("i = %lu\n",sizeof(i)/sizeof(i[0]) );
	printf("f = %lu\n",sizeof(f)/sizeof(f[0]) );
	printf("s = %lu\n",sizeof(s)/sizeof(s[0]) );

	return(0);
}
