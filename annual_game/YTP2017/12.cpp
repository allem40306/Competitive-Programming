#include <stdio.h>
#include <vector>

int vis[2020], low[2020], ins[2020], sta[2020], k, t, m; std::vector<int> v[2020];

int SCC(int i) {
	int j, l, c;
	for (vis[i] = low[i] = ins[i] = ++t, sta[k++] = i, j = 0, l = v[i].size(); j != l; j++)
		vis[v[i][j]] || SCC(v[i][j]), ins[v[i][j]] && low[i] > low[v[i][j]] && (low[i] = low[v[i][j]]);
	if (vis[i] <= low[i]) {
		for (c = 0, k--; sta[k] != i; c++, k--)
			ins[sta[k]] = 0;
		ins[i] = 0, c++, m < c && (m = c);
	}
}

int main() {
	int N, M, i, j;
	for (; ~scanf("%d%d", &N, &M); printf("%d\n", m)) {
		for (i = 1; i <= N; i++)
			vis[i] = low[i] = 0, v[i].clear();
		while (M--)
			scanf("%d%d", &i, &j), v[i].push_back(j);
		for (t = i = 1, k = m = 0; i <= N; i++)
			vis[i] || SCC(i);
	}
}
