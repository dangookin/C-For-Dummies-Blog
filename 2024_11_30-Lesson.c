/* Hex Words */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this code assumes the following path is valid */
#define DICTIONARY "/usr/share/dict/words"
#define SIZE 32

/* move this outside */
struct entry {
	char hex[SIZE];
	long value;
};

int compare(const void *a, const void *b)
{
	struct entry *x,*y;

	x = (struct entry *)a;
	y = (struct entry *)b;

	return( x->value - y->value );
}

int main()
{
	FILE *dict;
	char word[SIZE],hexword[SIZE],*r,*w;
	int count,x;
	struct entry *list;

	/* open the dictionary */
	dict = fopen(DICTIONARY,"r");
	if( dict==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",DICTIONARY);
		exit(1);
	}

	/* read the dictionary */
	count = 0;
	while( !feof(dict) )
	{
		/* read a word from the dictionary */
		r = fgets(word,SIZE,dict);
		if( r==NULL )	/* no word, done */
			break;

		/* remove newline */
		w = word;
		while(*w)
		{
			if( *w=='\n' )
			{
				*w = '\0';
				break;
			}
			w++;
		}
		
		/* pull out only hex characters */
		sscanf(word,"%[ABCDEFabcdef]",hexword);

		/* compare hexword with original word */
		if( strcmp(word,hexword)==0 && strlen(hexword)>3 )
		{
			if( count==0 )
			{
				list = malloc( sizeof(struct entry) );
				if( list==NULL )
				{
					fprintf(stderr,"Unable to allocate memory\n");
					exit(1);
				}
				strcpy( list->hex,hexword );
				list->value = strtol(hexword,NULL,16);
			}
			else
			{
				list = realloc( list, sizeof(struct entry) * (count+1) );
				if( list==NULL )
				{
					fprintf(stderr,"Unable to reallocate memory\n");
					exit(1);
				}
				strcpy( (list+count)->hex,hexword );
				(list+count)->value = strtol(hexword,NULL,16);
			}
			count++;
		}
	}

	/* sort the list */
	qsort(list,count,sizeof(struct entry),compare);

	/* output the list */
	for( x=0; x<count; ++x )
		printf("%3d: %-10s %10ld\n",
				x+1,
				(list+x)->hex,
				(list+x)->value
			  );

	/* clean-up */
	fclose(dict);
	free(list);
	return(0);
}
