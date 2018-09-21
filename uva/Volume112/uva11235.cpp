#include <iostream>
#include <cmath>
using namespace std;
const int N = 100005;
const int lg = 20;
int a[N], sum[N], L[N], R[N];
int st[lg][N];
void st_build() {
	for (int i = 0; i < N; i++) {
		st[0][i] = i;
	}
	for (int i = 1; (1 << i) - 1 < N; i++) {
		for (int j = 0; j + (1 << i) - 1 < N; j++) {
			int L = st[i - 1][j];
			int R = st[i - 1][j + (1 << (i - 1))];
			st[i][j] = (sum[L] >= sum[R] ? L : R);
		}
	}
}

int st_query(int a, int b) {
	if (a > b)return 0;
	int i = 31 - __builtin_clz(abs(b - a) + 1);
	int L = st[i][a];
	int R = st[i][b - (1 << i) + 1];
	// cout << L << ' ' << R << ' ' << sum[L] << ' ' << sum[R] << ' ';
	return max(sum[L], sum[R]);
}

int main() {
	int n, q;
	while (cin >> n, n) {
		cin >> q;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		L[0] = 0;
		sum[0] = 1;
		for (int i = 1; i < n; i++) {
			L[i] = (a[i] == a[i - 1] ? L[i - 1] : i);
			sum[i] = (a[i] == a[i - 1] ? sum[i - 1] + 1 : 1);
		}
		R[n - 1] = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			R[i] = (a[i] == a[i + 1] ? R[i + 1] : i);
		}
		st_build();
		for (int i = 0, x, y; i < q; i++) {
			cin >> x >> y;
			x--;
			y--;
			cout << max(max(min(y, R[x]) - x + 1, y - max(x, L[y]) + 1), st_query(R[x] + 1, L[y] - 1)) << '\n';
		}
	}

}
