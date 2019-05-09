#include <bits/stdc++.h>
using namespace std;
const int MXNT = 50005; // notice
using PII = pair<int, int>;
int NT, NTc[MXNT];
vector<int>route[MXNT];
struct Edge{
	int to, w, label;
	Edge(int _to = 0, int _w = 0, int _label = 0):
		to(_to), w(_w), label(_label){}
};

map<pair<int, int>, int> rid;

int getId(PII x){
	if(rid.count(x))return rid[x];
	int &r = rid[x];
    return r = rid.size();
}

vector<Edge>G[MXNT];
PII dist[MXNT];
int pre[MXNT][2];
bitset<MXNT> inq;

void spfa(int st){
	memset(dist, 0x3f, sizeof(dist));
	memset(pre, -1, sizeof(pre));
	inq.reset();
	int u, v;
	queue<int> Q;
	Q.push(st); dist[st] = make_pair(0, 0); inq[st] = 1;

	while(!Q.empty()){
		u = Q.front(); Q.pop();
		inq[u] = 0;
		for(auto it: G[u]){
			v = it.to;
			if(dist[v] > make_pair(dist[u].first + it.w, dist[u].second + 1)){
				dist[v] = make_pair(dist[u].first + it.w, dist[u].second + 1);
				pre[v][0] = u;
				pre[v][1] = it.label;
				if(inq[v])continue;
				inq[v] = 1;
				Q.push(v);
			}
		}
	}

}

void sol(int n, int a[]){
	for(int i = 0; i < MXNT; ++i)G[i].clear();
	rid.clear();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < NT; ++j){
			int st = i, ed = i;
			for(int k = 0; k != route[j].size(); ++k){
				if(ed + 1 < n && route[j][k] == a[ed + 1])ed++;
				int u = getId({st, route[j][0]});
				int v = getId({ed, route[j][k]});
				G[u].push_back(Edge(v, NTc[j], j));
				if(ed == n)break;
			}
		}
	}
	int st = getId({0, a[0]});
	int ed = getId({n - 1, a[n - 1]});
	spfa(st);

	vector<int> buy;
	for(int i = ed; i >= 0; i = pre[i][0]){
		buy.push_back(pre[i][1]);
	}
	cout << "Cost = " << dist[ed].first << "\n";
	cout << "  Tickets used:";
	for(int i = (int)buy.size() - 2; i >= 0; --i){
		cout << ' ' << buy[i] + 1;
	}
	cout << '\n';
}

int main(){
	int n, q, ti = 0;
	int a[MXNT];
	while(cin >> NT, NT){
		for(int i = 0; i < NT; ++i){
			int m;
			cin >> NTc[i] >> m;
			route[i].clear();
			for(int j = 0, x; j < m; ++j){
				cin >> x;
				route[i].push_back(x);
			}
		}
		cin >> q;
		++ti;
		for(int i = 1; i <= q; ++i){
			cin >> n;
			for(int i = 0; i < n; ++i){
				cin >> a[i];
			}
			cout << "Case " << ti << ", Trip " << i << ": ";
			sol(n, a);
		}
	}
}