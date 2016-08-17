#include <iostream>
#include <vector>
using namespace std;
#define N 10005
vector <int> adj[N];
bool vis[N];

void init(){
	for (int i = 0; i < N; i++){
		adj[i].clear();
		vis[i] = 0;
	}
	return;
}

void dfs(int i){
	vis[i] = 1;
	int len = adj[i].size();
	for (int j = 0; j < len; j++){
		if (!vis[adj[i][j]])
			dfs(adj[i][j]);
	}
}

int main(){
	int t, n, m, l, ti = 0;
	for (cin >> t; ti < t; ti++){
		cin >> n >> m >> l;
		init();
		for (int x,y,i = 0; i < m; i++){
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int z,j = 0; j < l; j++){
			cin >> z;
			dfs(z);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += vis[i];
		printf("%d\n", ans);
	}
}