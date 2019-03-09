#include <stdio.h>

int main()
{
	int a;
	char buf[4];

	for(a=1;a<=100;a++)
	{
		sprintf(buf,"%d",a);
		printf("%s\n",
				a%3 && a%5 ? buf :
				a%3 ? "Buzz" :
				a%5 ? "Fizz" :
				"FizzBuzz"
			  );
	}

	return(0);
}
		
