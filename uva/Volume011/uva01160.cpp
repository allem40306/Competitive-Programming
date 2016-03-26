#include <iostream>
#include <cstdio>
using namespace std;
#define N 100005

struct disjointset{
	int p[N];
	void init(int n){
		for (int i = 0; i < n; i++)
			p[i] = i;
	}
	int find(int x){
		return x == p[x] ? x : find(p[x]);
	}
	void Union(int a, int b){
		p[find(a)] = find(b);
	}
}djs;

int main() {
	int a, b;
	while (cin >> a){
		int ans = 0;
		cin >> b;
		djs.init(N);
		djs.Union(a, b);
		while (cin >> a, a != -1){
			cin >> b;
			if (djs.find(a) != djs.find(b))
				djs.Union(a, b);
			else ans++;
		}
		printf("%d\n", ans);
	}
}