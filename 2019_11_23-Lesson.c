#include <stdio.h>

void left(void)
{
	puts("left");
}

void right(void)
{
	puts("right");
}

int main()
{
	struct f {
		void (*f1)();
		void (*f2)();
	};
	struct f func;

	func.f1 = &left;
	func.f2 = &right;

	func.f1();
	func.f2();

	return(0);
}
