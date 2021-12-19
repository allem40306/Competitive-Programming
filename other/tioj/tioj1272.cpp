#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
#define lowbit(x) (x&(-x))
int tot = 0, tin[N], tout[N];
vector<int>v[N];

void dfs(int s) {
	tin[s] = ++tot;
	for (int i=0;i<v[s].size();i++) {
		dfs(v[s][i]);
	}
	tout[s] = tot;
	return;
}

bool sum[N];

void add(int x) {
	while (x < N) {
		sum[x] ^= 1;
		x += lowbit(x);
	}
}

bool Sum(int x) {
	bool b = 0;
	while (x > 0) {
		b ^= sum[x];
		x -= lowbit(x);
	}
	return b;
}

int main() {
	int n, m;
	bitset<N>c;
	cin >> n >> m;
	c.reset();
	for (int i = 1, x, y; i <= n; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> y;
			v[i].push_back(y);
			// cout<<i<<'-'<<y<<'\n';
			c[y] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (c[i])continue;
		dfs(i);
		break;
	}
	for(int i=0,x,y;i<m;i++){
		cin>>x>>y;
		if(x){
			cout<<Sum(tin[y])<<'\n';
		}else{
			add(tin[y]);
			add(tout[y]+1);
		}
	}
}
