//https://en.cppreference.com/w/c/language/object#Alignment
#include <stdio.h>

struct alpha {
	char c;
	long i;
};

int main()
{
	struct alpha a;
	char string[] = "abcdefghijk";
	int beta = 0;

	printf("The structure occupies %zu bytes\n",sizeof(struct alpha) );
	printf("The structure aligns at %zu bytes\n",_Alignof(struct alpha) );
	printf("The structure sits at location %p\n",&a);
	printf("The string occupies %zu bytes\n",sizeof(string) );
	printf("The string aligns at %zu bytes\n",_Alignof(string) );
	printf("The string sits at location %p\n",string);
	printf("The integer occupies %zu bytes\n",sizeof(beta) );
	printf("The integer aligns at %zu bytes\n",_Alignof(beta) );
	printf("The integer sits at location %p\n",&beta);

	return 0;
}
