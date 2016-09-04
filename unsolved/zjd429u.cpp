#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 105
int  low[N], depth[N], n, search;
bool iscut[N], visit[N], adj[N][N];

void init(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			adj[i][j] = 0;
		depth[i] = iscut[i] = visit[i] = 0;
	}
	return;
}

void dfs(int now, int cur_depth){
	search++;
	visit[now] = true;
	depth[now] = low[now] = cur_depth;
	iscut[now] = false;
	int cut_son = 0;
	for (int i = 1; i <= n; i++){
		if (adj[now][i]){
			if (visit[i]){
				if (depth[i] < low[now])
					low[now] = depth[i];
			}
			else{
				dfs(i, cur_depth + 1);
				cut_son += 1;
				if (low[i] < low[now])
					low[now] = low[i];
				if (low[i] >= depth[now])
					iscut[now] = true;
			}
		}
	}
	if (cur_depth == 0 && cut_son == 1)
		iscut[now] = false;
	return;
}

int ncut(){
	int cut = 0;
	dfs(1, 0);
	for (int i = 0; i <= n; i++)
		if (iscut[i])cut++;
	return cut;
}

int main(){
	while (cin >> n){
		int a, b;
		while (cin >> a, a){
			cin >> b;
			adj[a][b] = adj[b][a] = 1;
		}
	search = 0;
	printf("%d\n", ncut()+(n-search));
	}
}