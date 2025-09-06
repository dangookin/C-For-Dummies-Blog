#include <stdio.h>

char *title(void)
{
	static char t[] = "Fun Array Stuff";

	printf("'%s' contains %zu bytes\n",
			t,
			sizeof(t)
		  );

	return(t);
}

int main()
{
	printf("'%s' contains %zu bytes\n",
			title(),
			sizeof( title() )
		  );

	return 0;
}
