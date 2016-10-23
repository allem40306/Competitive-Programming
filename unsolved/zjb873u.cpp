#include <iostream>
#include <cstring>
using namespace std;
#define N 10005
int t, ti = 0, n, q, qq, to[N];
bool vis[N];

int dfs(){
	memset(vis, 0, sizeof(vis));
	vis[qq] = 1;
	if (qq == to[qq] || qq == to[to[qq]])return-1;
	while (1){
		qq = to[qq];
		if (qq == to[qq] || qq == to[to[qq]])return-1;
		if (vis[qq])return 1;
	}
}

int main() {
	for (cin >> t; ti < t; ti++){
		cin >> n;
		for (int ni = 1; ni <= n; ni++)
			cin >> to[ni];
		cin >> q;
		for (int qi = 0; qi < q; qi++){
			cin >> qq;
			cout << dfs() << endl;
		}
	}
}