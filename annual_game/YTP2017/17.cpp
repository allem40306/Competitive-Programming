#include <stdio.h>
#include <vector>

int vis[1010], low[1010], t, c; std::vector<int> v[1010];

int gcd(int a, int b) {
	for (int t; b; )
		t = a%b, a = b, b = t;
	return a;
}

int DFS(int f, int i) {
	int j, l, ap, w;
	for (vis[i] = low[i] = t++, ap = w = j = 0, l = v[i].size(); j != l; j++)
		f != v[i][j] && (vis[v[i][j]] ? (low[i] > vis[v[i][j]] && (low[i] = vis[v[i][j]])) : (DFS(i, v[i][j]), low[i] > low[v[i][j]] && (low[i] = low[v[i][j]]), vis[i] <= low[v[i][j]] && w++, ap++));
	(f ? w : ap >= 2) && c++;
}

int main() {
	int N, i, j, n[1010], num[30300];
	for (; ~scanf("%d", &N); printf("%d\n", c)) {
		for (i = 1; i <= N; i++)
			scanf("%d", &n[i]), num[n[i]] = i, v[i].clear();
		for (i = 1; i <= N; i++)
			for (j = i+1; j <= N; j++)
				gcd(n[i], n[j])-1 && (v[num[n[i]]].push_back(num[n[j]]), v[num[n[j]]].push_back(num[n[i]]), 1);
		for (t = i = 1, c = 0; i <= N; i++)
			vis[num[n[i]]] || DFS(0, i);
	}
}
