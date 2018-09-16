#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 3005;
struct Edge {
	int t, w;
	Edge(int t, int w): t(t), w(w) {}
};

int main() {
	int m, n, k, s, t, w;
	int d[N];
	vector<Edge>v[N];
	queue<int>q;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> s >> t >> w;
		v[s].push_back(Edge(t, w));
		v[t].push_back(Edge(s, w));
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 9000000;
	}
	bool vis[N] = {};
	for (int i = 0; i < k; i++) {
		cin >> s;
		d[s] = 0;
		vis[s] = 1;
		q.push(s);
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		vis[x] = 0;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].t, z = v[x][i].w;
			// cout << x << ' ' << y << ' ' << z << '\n';
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				if (!vis[y])q.push(y);
			}
		}
	}
	int ans = d[1];
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]);
		// cout << i << ' ' << d[i] << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			ans = max(ans, (d[i] + d[v[i][j].t] + v[i][j].w + 1) / 2);
		}
	}
	cout << ans << '\n';
}
