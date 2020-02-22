#include <stdio.h>
#include <unistd.h>

int main()
{
	char *password;

	/* fetch the password */
	password = getpass("Your password: ");
	printf("Your password is '%s'\n",password);

	return(0);
}
