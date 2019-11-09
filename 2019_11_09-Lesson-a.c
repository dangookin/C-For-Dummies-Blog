#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		int age;
		char name[12];
	} man = { 34, "George" };
	struct person *guy;

	/* output the structure */
	printf("%s is %d years old\n",man.name,man.age);

	/* allocate the buffer */
	guy = (struct person *)malloc( sizeof(struct person) );
	if( guy==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* copy memory */
	memcpy(guy,&man,sizeof(struct person));

	/* output the duplicate structure */
	printf("%s is %d years old\n",guy->name,guy->age);

	return(0);
}
