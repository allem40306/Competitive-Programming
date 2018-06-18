#include <iostream>
#include <cstring>
using namespace std;
#define N 105

int main() {
	int m, n, w, x, y, z, a[N][2], ans, i, j;
	while (scanf("%d %d %d %d %d %d", &m, &n, &w, &x, &y, &z)!=EOF){
		memset(a, 0, sizeof(a));
		a[0][0] = m; a[0][1] = n;
		for (i = 1; i <=w ; i++){
			if (i - x >= 0){
				a[i][0] += a[i-x][1];
				a[i - x][1] = 0;
			}
			for (j = i - y; j >= 0; j -= y)
				a[i][1] += a[j][0] * z;
		}
		for (i = ans = 0; i <= w; i++)
			ans += a[i][0] + a[i][1];
		printf("%d\n", ans);
	}
}