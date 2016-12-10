#include <iostream>
#include <cstring>
#define N 1000
#define Min(x,y) x<y?x:y

int main(){
	static int a[N][N], i, j, t, ti=0, m, n;
	for (scanf("%d", &t); ti<t; ti++){
		scanf("%d %d", &n, &m);
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		for (i = 1; i<N; i++){
			a[i][1] += a[i - 1][1];
			a[1][i] += a[1][i - 1];
		}
		for (i = 2; i <= n; i++)
			for (j = 2; j <= m; j++)
				a[i][j] += Min(a[i - 1][j], a[i][j - 1]);
		printf("%d\n", a[n][m]);
	}
}
