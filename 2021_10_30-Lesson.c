#include <stdio.h>

int main()
{
	/* define the structure */
	struct human {
		char name[32];
		int age;
		float iq;
	};

	/* declare a variable and set values */
	struct human you = {
		.iq = 189.6,
		.name = "See Programmer",
		.age = 29
	};

	printf("You are %s, age %d, IQ %.1f\n",
			you.name,
			you.age,
			you.iq
		  );

	return(0);
}
