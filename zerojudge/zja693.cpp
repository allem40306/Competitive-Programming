#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int n, arr[100005], heap[200020];

void init() {
	memset(arr, 0, sizeof(arr));
	memset(heap, -1, sizeof(heap));
	return;
}

int bulit(int L, int R, int x) {
	if (L == R)
		return heap[x - 1] = arr[L];
	int M = (L + R) / 2;
	heap[x - 1] = bulit(L, M, (x << 1)) + bulit(M + 1, R, (x << 1) + 1);
	return heap[x - 1];
}

int ans,a, b;

void quest(int L, int R, int x) {
	if (a <= L&&R <= b){
		ans += heap[x - 1];
		return;
	}
	int M = (L + R) / 2;
	if (a <= M)quest(L, M, (x << 1));
	if (b > M)quest(M + 1, R, (x << 1) + 1);
	return;
}

int main() {
	int n, m, q1, q2;
	while (cin>>n>>m) {
		init();
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		bulit(1, n, 1);
		for (int j = 0; j < m; j++){
			ans = 0;
			cin >> a >> b;
			quest(1, n, 1);
			printf("%d\n",ans);
		}
	}
}
