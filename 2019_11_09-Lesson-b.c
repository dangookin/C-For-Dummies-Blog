#include <stdio.h>

int main()
{
	struct person {
		int age;
		char name[12];
	} man = { 34, "George" };
	struct person guy;

	/* output the structure */
	printf("%s is %d years old\n",man.name,man.age);

	/* copy structure */
	guy = man;

	/* output the duplicate structure */
	printf("%s is %d years old\n",guy.name,guy.age);

	return(0);
}
