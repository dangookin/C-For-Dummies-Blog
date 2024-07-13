#include <stdio.h>

void one(char **words)
{
	/*
	 	**words is the base of the array
		**words is also the first string's first character
		*words is the first string
	*/
	puts("You have passed the entire array:");
	while(*words)
		puts(*words++);
}

void two(char *word)
{
	/*
	   word is a string
	   *word is the first character of the string
    */
	puts("You have passed a single string:");
	puts(word);
}

int main()
{
	char *words[] = {
		"alpha", "beta", "gamma", "delta", NULL
	};

	one(words);
	two(*words);

	return 0;
}
