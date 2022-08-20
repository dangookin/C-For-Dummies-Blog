#include <stdio.h>

int main()
{
	int v;

	for( v=0; v<1050; v++ )
		printf("-%d & %d = %d\n",
				v,
				v,
				-v & v
			  );

	return(0);
}
