#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 500005
int a, b, n,m, t, ans, arr[N], heap[2 * N];

void init() {
	memset(arr, 0, sizeof(arr));
	memset(heap, -1, sizeof(heap));
	return;
}

int bulit(int L, int R, int x) {
	if (L == R)
		return heap[x] = arr[L];
	int M = (L + R) / 2;
	heap[x] = max( bulit(M + 1, R, (x << 1) + 1),bulit(L, M, (x << 1)));
	return heap[x];
}

void quest(int L, int R, int x, int a, int b) {
	if (a <= L&&R <= b){
		ans = max(ans, heap[x]);
		return;
	}
	int M = (L + R) / 2;
	if (a <= M)quest(L, M, (x << 1), a, b);
	if (b > M)quest(M + 1, R, (x << 1) + 1, a, b);
	return;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		init();
		for (int ni = 1; ni <= n; ni++)
			scanf("%d", &arr[ni]);
		bulit(1, n, 1);
		scanf("%d", &m);
		for (int mi = 0; mi<m; mi++){
			scanf("%d %d", &a, &b);
			if (a>b)t = a, a = b, b = t;
			ans = 0;
			quest(1, n, 1, a, b);
			printf("%d\n", ans);
		}
	}
}
