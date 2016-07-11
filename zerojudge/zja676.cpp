#include <iostream>
using namespace std;
#define N 100
#define maxx(x,y) x>y?x:y

int main() {
	int n, a[N], b[N], c[N][N], x;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> x, a[x] = i;
	while (cin >> x){
		b[x] = 1;
		for (int i = 2; i <= n; i++)
			cin >> x, b[x] = i;
		for (int i1 = 0; i1 < N; i1++)
			for (int j1 = 0; j1 < N; j1++)
				c[i1][j1] = 0;
		for (int i2 = 1; i2 <= n; i2++)
			for (int j2 = 1; j2 <= n; j2++)
				c[i2][j2] = (a[i2] == b[j2] ? c[i2 - 1][j2 - 1] + 1 : maxx(c[i2 - 1][j2], c[i2][j2 - 1]));
		printf("%d\n", c[n][n]);
	}
}