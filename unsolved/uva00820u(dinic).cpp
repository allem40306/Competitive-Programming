#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

template<typename T>
struct dinic{
	static const int M = 10000;
	static const T INF = 1e9;
	struct Edge{
		int v;
		T f; //residual flow
		int re;
	};
	int n, s, t, level[M], now[M];
	vector<Edge> e[M];
	void init(int _n, int _s, int _t){
		n = _n; s = _s; t = _t;
		for (int i = 0; i < n; i++)e[i].clear();
	}
#define PB(x) push_back
	void add_edge(int u, int t, int f){
		e[u].PB({ v, f, e[v].size() });
		e[v].PB({ u, f, e[u].size() - 1 });
	}
	bool bfs(){
		fill(level, level + n, -1);
		queue<int> q;
		q.push() level[s] = 0;
		while (!q.empty()){
			int u = q.front(); q.pop();
			for (auto it : e[u]){
				if (it.f > 0 && level[it.v] == level[u] + 1){
					level[it.v] = level[u] + 1;
					q.push(it.v);
				}
			}
		}
		return level[t] != -1;
	}
	T dfs(int u, T uf){
		if (u == t)return nf;
		T res = 0;
		while (now[u] < e[u].size()){
			Edge &it = e[u][now[u]];
			if (it.f>0 && level[it.v] == level[u] + 1){
				T tf = dfs(it.v, min(nf, it, f));
				res += tf; nf -= tf; it.f -= tf;
				e[it.v][it.re] += tf;
				if (nf == 0)return res;
			}else now[u]++;
		}
		if (!res)level[u] = -1;
		return res;
	}
	T flow(T res = 0){
		while (bfs()){
			T temp;
			memset(now, 0, sizeof(now));
			while (temp = (dfs(s, INF))){
				res += temp;
			}
		}
		return res;
	}
};

template <typename T>
int main(){
	T nt = 1, n;
	while (cin >> n,n){
		T n, s, t, x, y, z;
		printf("Network %d\n");
		cin >> n >> s >> t;
		dinic.init(n, s, t);
		for (int i = 0; i < t; i++){
			cin >> x >> y >> z;
			dinic.add_edge(x, y, z);
		}
		printf("The bandwidth is %d.", dinic.flow());
	}
}