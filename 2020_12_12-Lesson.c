#include <stdio.h>

int main()
{
    double fibo,nacci;
	int count;

    fibo = nacci = 1.0;
	count=0;

    do
    {
        printf("%.0f\n",fibo);
        fibo+=nacci;
        printf("%.0f\n",nacci);
        nacci+=fibo;
		count+=2;
    } while( count < 100 );

    return(0);
}
