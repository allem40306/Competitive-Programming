#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int main() {
	int n, m;
	long long a[N], ans = 10000000000;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i + m <= n; i++) {
		if (a[i] <= 0 && 0 <= a[i + m - 1]) {
			ans = min(ans, 2 * (a[i + m - 1] - a[i]) - max(-a[i], a[i + m - 1]));
		} else {
			ans = min(ans, max(abs(a[i + m - 1]), abs(a[i])));
		}
		// cout << i << ' ' << ans << '\n';
	}
	cout << ans << '\n';
}
