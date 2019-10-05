#include <stdio.h>
#include <stdlib.h>

#define SIZE 12
#define CLASSES 5

float get_grade(void)
{
	char input[SIZE];
	float grade;
	char *p;

	/* obtain input */
	fgets(input,SIZE,stdin);
	/* convert to float */
	grade = strtod(input,&p);
	/* validate */
	if( p==input )
	{
		puts("Inavlid input");
		exit(1);
	}
	/* confirm range */
	if( grade<0 || grade>100 )
	{
		puts("Input out of range");
		exit(1);
	}

	/* return GPA value */
	if( grade > 89 )
		return(4.0);
	if( grade > 79 )
		return(3.0);
	if( grade > 69 )
		return(2.0);
	if( grade > 59 )
		return(1.0);

	return(0.0);
}

int main()
{
	float gpa,average;
	int x;

	/* obtain input */
	gpa = 0.0;
	for( x=0; x<CLASSES; x++)
	{
		printf("Enter grade (0 to 100) for class #%d: ",x+1);
		gpa += get_grade();
	}
	average = gpa/(float)CLASSES;

	/* output results */
	printf("Your semester GPA is %.1f\n",average);

	return(0);
}
