#include <bits/stdc++.h>
using namespace std;
const int N = 55;

struct Edge {
	int s, t;
	double w;
	Edge() {};
	Edge(int _s, int _t, double _w): s(_s), t(_t), w(_w) {}
};

struct BellmanFrod {
	int n, m;
	vector<Edge>edges;
	vector<int>g[N];
	double d[N];
	int p[N], cnt[N];
	bool inq[N];
	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		edges.clear();
	}
	void AddEdges(int s, int t, double w) {
		edges.push_back(Edge(s, t, w));
		m = edges.size();
		g[s].push_back(m - 1);
	}
	bool negativeCycle() {
		queue<int>q;
		memset(inq, 0, sizeof(inq));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			d[i] = 0;
			inq[i] = 1;
			q.push(i);
		}
		while (!q.empty()) {
			int x = q.front(); q.pop();
			inq[x] = 0;
			for (int i = 0; i < g[x].size(); i++) {
				Edge& e = edges[g[x][i]];
				if (d[e.t] > d[x] + e.w) {
					d[e.t] = d[x] + e.w;
					p[e.t] = g[x][i];
					if (!inq[e.t]) {
						q.push(e.t);
						inq[e.t] = 1;
						if (++cnt[e.t] > n) {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
} B;

bool judge(double x) {
	for (int i = 0; i < B.m; i++) {
		B.edges[i].w -= x;
	}
	bool tmp = B.negativeCycle();
	for (int i = 0; i < B.m; i++) {
		B.edges[i].w += x;
	}
	return tmp;
}

int main() {
	int T, n, m, s, t;
	double w, mxw;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		cin >> n >> m;
		B.init(n);
		mxw = 0;
		for (int i = 0; i < m; i++) {
			cin >> s >> t >> w;
			s--; t--;
			B.AddEdges(s, t, w);
			mxw = max(mxw, w);
		}
		cout << "Case #" << ti << ": ";
		if (!judge(mxw+1)) {cout << "No cycle found.\n";}
		else {
			double L = 0, R = mxw, M;
			for (int i = 0; i < 100; i++) {
				M = (L + R) / 2;
				if (!judge(M))L = M;
				else R = M;
			}
			cout << fixed << setprecision(2) << L << '\n';
		}
	}
}