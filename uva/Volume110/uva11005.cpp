#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 40
LL cost[N], ans[N];

LL sol(LL n, LL x) {
	LL v = 0;
	while (n) {
		v += cost[n % x];
		n /= x;
	}
	return v;
}

int main() {
	int t, q;
	LL n, mn;
	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		for (int i = 0; i < 36; i++) {
			cin >> cost[i];
		}
		if (ti > 1)cout << '\n';
		cout << "Case " << ti << ":\n";
		cin >> q;
		while (q--) {
			cin >> n;
			for (LL i = 2; i <= 36; i++) {
				ans[i] = sol(n, i);
			}
			mn = *min_element(ans + 2, ans + 36 + 1);
			cout << "Cheapest base(s) for number " << n << ':';
			for (int i = 2; i <= 36; i++) {
				if (ans[i] == mn)cout << ' ' << i;
			}
			cout << '\n';
		}
	}
}