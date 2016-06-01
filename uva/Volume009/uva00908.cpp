#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000003

int p[N];
void init(){
	for (int i = 0; i < N; i++)
		p[i] = i;
}
int find(int x){
	return x == p[x] ? x : find(p[x]);
}

struct edge{
	int a, b, d;
};

bool cmp(edge a, edge b){
	return a.d < b.d;
}

int main() {
	int n, m, k, i, it = 0;
	while (cin >> n){
		if (it++)printf("\n");
		edge e[N];
		int a, b, d;
		int ans = 0, ans2 = 0, er = 0;
		for (i = 0; i < n - 1; i++){
			cin >> a >> b >> d;
			ans += d;
		}
		cin >> k;
		for (i = 0; i < k; i++){
			cin >> e[er].a >> e[er].b >> e[er].d;
			er++;
		}
		cin >> m;
		for (i = 0; i < m; i++){
			cin >> e[er].a >> e[er].b >> e[er].d;
			er++;
		}
		sort(e, e + er,cmp);
		init();
		int nn = 0;
		for (i = 0; nn < n-1; i++){
			int fa = find(e[i].a), fb = find(e[i].b);
			if (fa != fb){
				ans2 += e[i].d;
				p[fa] = fb;
				nn++;
			}
		}
		cout << ans << endl << ans2 << endl;
	}
}