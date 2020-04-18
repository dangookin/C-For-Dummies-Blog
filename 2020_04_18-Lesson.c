#include <stdio.h>

void arguments( int a, int b, int c, int d, int e, int f,
		int g, int h, int i, int j, int k, int l, int m,
		int n, int o, int p, int q, int r, int s, int t,
		int u, int v, int w, int x, int y, int z )
{
	printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\
%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
			a, b, c, d, e, f, g, h, i, j, k, l, m,
			n, o, p, q, r, s, t, u, v, w, x, y, z
		  );
}

int main()
{
	arguments( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
			14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26);

	return(0);
}
