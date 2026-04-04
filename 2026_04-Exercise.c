#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* find the first non-space character
   on the right */
char *rtrim(char *s)
{
	char *right = NULL;

	right = s+strlen(s)-1;
	while( isspace(*right) )
	{
		right--;
	}
	
	return(right);
}

/* find the first non-space character
   on the left */
char *ltrim(char *s)
{
	char *left = NULL;

	left = s;
	while( isspace(*left) )
	{
		if( *left=='\0' )
			break;
		left++;
	}

	return(left);
}

/* trim spaces from the left and right
   of a string; return the new string */
char *trim(char *s)
{
	char *trimmed,*front,*back;
	int offset;

	/* test for NULL pointer */
	if( s==NULL )
		return(s);	/* return NULL pointer */

	/* find the ends */
	back = rtrim(s);
	front = ltrim(s);
	
	/* allocate storage */
	if( back>front )
		/* string contains some text */
		trimmed = malloc( sizeof(char) * (back-front) + 1 );
	else
		/* string is empty or all spaces */
		trimmed = malloc( sizeof(char) * 1 );

	/* create the trimmed string */
	if( trimmed!=NULL )
	{
		/* empty string test */
		if( sizeof(trimmed)==1 )
		{
			*trimmed = '\0';		/* empty string */
		}
		else
		{
			/* copy the center */
			offset = 0;
			while( front<=back )
			{
				*(trimmed+offset) = *front;
				front++;
				offset++;
			}
			*(trimmed+offset)='\0';
		}
	}

	return(trimmed);
}

int main()
{
	char *sample[] = {
		"   one   ",
		"\ttwo\n",
		"",
		"    ",
		"a",
		" x ",
		NULL,
		" \t three \n",
		"four",
		"  five",
		"six    ",
		" seven eight "
	};
	int size,x;
	char *t;

	/* obtain array size */
	size = sizeof(sample)/sizeof(sample[0]);

	/* output trimmed strings */
	for( x=0; x<size; x++ )
	{
		printf("'%s' => ",sample[x]);
		t = trim(sample[x]);
		if( t==NULL )
		{
			printf("Bad string\n");
		}
		else
		{
			printf("'%s'\n",t);
			free(t);
		}
	}

	return 0;
}
