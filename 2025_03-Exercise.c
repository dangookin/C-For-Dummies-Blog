#include <stdio.h>
#include <string.h>

int main()
{
    char phrase[] = "Was this the face that launch'd a thousand ships, and burnt the topless towers of Ilium?";
    char find[] = "the";
    char *found;

    puts(phrase);
    found = strstr(phrase,find);
    if( found==NULL )
        printf("String '%s' not found\n",find);
    else
    {
        printf("Found '%s' at offset %d.\n", find, (int)(found-phrase));
        do
        {
            found = strstr(found+1,find);
            if( found != NULL )
                printf("Found '%s' at offset %d.\n", find, (int)(found-phrase));
        }
        while( found != NULL );
    }

    return 0;
}
