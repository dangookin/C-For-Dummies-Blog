#include <stdio.h>

int main()
{
	int x,y;

	for( x=1,y=10; y>0; x++,y-- )
		printf("%2d %% %2d = %d\n",x,y,x%y);

	printf("%d %% %d = %d\n",5,10,5%10);
	printf("%d %% %d = %d\n",2,8,2%8);
	printf("%d %% %d = %d\n",7,1500,7%1500);
	printf("%d %% %d = %d\n",4,4,4%4);
	printf("%d %% %d = %d\n",10,5,10%5);
	printf("%d %% %d = %d\n",8,2,8%2);
	printf("%d %% %d = %d\n",1500,7,1500%7);
	return(0);

}
