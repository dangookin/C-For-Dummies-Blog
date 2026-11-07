#include <iostream>
using namespace std;
#define N 10

int main()
{
	static int i = 1;
	if( i <= N && cout << i++ << "\n" ) {
		main();
	}

	return 0;
}
