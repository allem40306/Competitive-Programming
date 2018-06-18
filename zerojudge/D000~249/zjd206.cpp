#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define N 105
#define MAX(x,y) x>y?x:y
int main() {
	int n, p = 1;
	while (cin >> n){
		int a[N][N], i, j, x, y;
		for (i = 0; i < N; i++){
			a[i][0] = a[0][i] = 0;
		}
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++){
			cin >> a[i][j];
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			}
		int mmax = -10000000;
		for (x = 1; x <= n; x++){
			for (y = 1; y <= n; y++){
				for (i = x; i <= n; i++){
					for (j = y; j <= n; j++){
						mmax = MAX(mmax, a[i][j] - a[i - x][j] - a[i][j - y] + a[i - x][j - y]);
					}
				}
			}
		}
		printf("%d\n", mmax);
	}
}