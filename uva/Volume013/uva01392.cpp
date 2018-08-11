#include <bits/stdc++.h>
using namespace std;
const int N = 150005;

struct Data {
	int sum, id, v;
} a[N], b[N];

int bs(int L, int R, int v) {
	int M;
	while (L < R) {
		M = (L + R) >> 1;
		if (b[M].v<=v)R = M;
		else L = M + 1;
	}
	return b[L].id;
}

int main() {
	int n, p, bi, ans;
	string s, t;
	while (cin >> n >> p, n || p) {
		cin >> s >> t;
		a[0].sum = a[0].id = a[0].v = 0;
		b[0] = a[0];
		ans = 0; bi = 1;
		for (int i = 1; i <= n; i++) {
			a[i].sum = a[i - 1].sum + (s[i - 1] != t[i - 1]);
			a[i].id = i;
			a[i].v = i * p - 100 * a[i].sum;
			if (a[i].v < b[bi - 1].v) {
				b[bi] = a[i];
				bi++;
			} else {
				int x = bs(0, bi, a[i].v);
				ans = max(ans, a[i].id - x);
			}
		}
		if (ans) {
			cout << ans << '\n';
		} else {
			cout << "No solution.\n";
		}
	}
}