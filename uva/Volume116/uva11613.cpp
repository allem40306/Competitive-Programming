#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int NN = 500;
const int MM = 15000;
#define INF 1e18
struct Edge {
	int s, t;
	LL cap, flow, cost;
};

vector<Edge>edges;
vector<int>G[MM];

void addEgde(int s, int t, LL cap, LL cos) {
	cout << s << ' ' << t << ' ' << cap << ' ' << cos << '\n';
	edges.push_back(Edge{s, t, cap, 0, cos});
	G[s].push_back(edges.size() - 1);
	edges.push_back(Edge{t, s, 0, 0, -cos});
	G[t].push_back(edges.size() - 1);
}

int inq[NN], p[NN];
LL d[NN], a[NN];

int BF(int s, int t, LL& flow, LL& cost) {
	memset(inq, 0, sizeof(inq));
	memset(a, 0, sizeof(a));
	memset(p, 0, sizeof(p));
	queue<int>q;
	for (int i = 0; i < NN; i++)d[i] = INF;
	d[s] = 0; a[s] = INF; inq[s] = 1; p[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		inq[x] = 0;
		for (int i = 0; i < G[x].size(); i++) {
			Edge &e = edges[G[x][i]];
			if (e.cap > e.flow && d[e.t] > d[x] + e.cost) {
				d[e.t] = d[x] + e.cost;
				a[e.t] = min(a[x], e.cap - e.flow);
				p[e.t] = G[x][i];
				if (!inq[e.t]) {
					inq[e.t] = 1;
					q.push(e.t);
				}
			}
		}
	}
	if (d[t] > 0)return 0;
	flow += a[t];
	cost += (LL)d[t] * (LL)a[t];
	for (int i = t; i != s; i = edges[p[i]].s) {
		edges[p[i]].flow += a[t];
		edges[p[i] ^ 1].flow -= a[t];
	}
	return 1;
}

int u, v;
LL sol() {
	LL cost = 0, flow = 0;
	while (BF(u, v, flow, cost));
	return cost;
}

int main() {
	int T, M, I, m, n, p, s, e;
	cin >> T;
	for (int ti = 1; ti <= T ; ti++) {
		cin >> M >> I;
		for (int i = 0; i < MM; i++)G[i].clear();
		edges.clear();
		u = 0; v = 2 * M + 1;
		for (int i = 1; i <= M; i++) {
			cin >> m >> n >> p >> s >> e;
			addEgde(u, i, n, m);
			for (int j = 0; j <= e; j++) {
				if (i + j <= M)addEgde(i, i + j + M, INF, I * j);
			}
			addEgde(i + M, v, s, -p);
		}
		cout << "Case " << ti << ": " << -sol() << '\n';
	}
	return 0;
}