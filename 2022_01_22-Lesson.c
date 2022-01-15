#include <stdio.h>
#include <ctype.h>

int sign(int a)
{
    /* value is negative */
    if( a<0 ) return(-1);

    /* value is positive */
    if( a>0 ) return(1);

    /* value is zero */
    return(0);
}

int strcasecmp(const char *s1, const char *s2)
{
    int offset,ch;
    unsigned char a,b;

    offset = 0;
    ch = 0;
    while( *(s1+offset)!='\0' || *(s2+offset)!='\0' )
    {
        a = (unsigned)*(s1+offset);
        b = (unsigned)*(s2+offset);
        ch = toupper(a) - toupper(b);
        if( ch<0 || ch>0 )
            return( sign(ch) );
        offset++;
    }

    return( sign(ch) );
}

void test(const char *s1, const char *s2)
{
    printf("%s v. %s = ",s1,s2);
    if( strcasecmp(s1,s2)==0 )
        puts("match");
    else
        puts("no match");
}

int main()
{
    char string1[] = "I drink coffee";
    char string2[] = "I DRINK COFFEE";
    char string3[] = "I drink tea";
	char string4[] = "I drink co";
	char string5[] = "I drink coffee and tea";

    test(string1,string1);
    test(string1,string2);
    test(string1,string3);
    test(string1,string4);
    test(string1,string5);

    return(0);
}
