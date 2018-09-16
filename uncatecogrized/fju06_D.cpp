#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
const int N = 100000;
long long t[N], tt[N], ans[N], mx;
vector<int>v[N], w[N];
bitset<N>b, e;

long long dfs(int s) {
	if (tt[s])return tt[s];
	long long tot = 0;
	for (int i : v[s]) {
		tot = max(tot, dfs(i));
	}
	return tt[s] = tot + t[s];
}

long long dfs2(int s) {
	if (ans[s] == -1 || tt[s] == mx)return -1;
	long long mn = mx;
	bool ok = 1;
	// cout << '-' << s << '\n';
	for (int i : w[s]) {
		// cout << i << "**\n";
		int x = (mn, dfs2(i));
		if (x == -1)ok = 0;
		if (ok && x < mn)mn = x;
	}
	if (!ok)return ans[s] = -1;
	ans[s] = mn - tt[s];
	// cout << s << ' ' << ans[s] << '\n';
	return mn - t[s];
}

int main() {
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	b.set(); e.set();
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		w[x].push_back(y);
		v[y].push_back(x);
		e[x] = 0;
		b[y] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!e[i])continue;
		int t = dfs(i);
		if (t > mx) {
			mx = t;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!b[i])continue;
		dfs2(i);
	}
	for (int i = 1; i <= n; i++) {
		cout << (ans[i] == -1 ? 0 : ans[i]) << '\n';
	}
}
