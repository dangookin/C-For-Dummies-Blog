#include <stdio.h>

#define s1 "Goodbye, "
#define s2 "cruel world!"

#define output(x) s##x

int main()
{
	printf("%s%s\n",
			output(1),
			output(2)
		  );

	return(0);
}
