#include <stdio.h>

/* assumes `char` array */
void key_dump(char *k[])
{
	int x = 0;

	while( k[x] )
	{
		printf("'%s'\n",
				k[x]
			  );
		x+=2;
	}
}

/* assumes `char` array */
void array_dump(char *a[])
{
	int x = 0;

	while( a[x] )
	{
		printf("'%s' => '%s'\n",
				a[x],
				a[x+1]
			  );
		x+=2;
	}
}

int main()
{
	char *months[] =
	{
		"January", "janvier",
		"February", "fevrier",
		"March", "mars",
		"April", "avril",
		"May", "mai",
		"June", "juin",
		"July", "julliet",
		"August", "aout",
		"September", "septembre",
		"October", "octobre",
		"November", "novembre",
		"December", "decembre",
		NULL, NULL
	};

	puts("Array Dump");
	array_dump(months);

	puts("Key DUmp");
	key_dump(months);

	return(0);
}
