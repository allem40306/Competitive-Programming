#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int n, arr[300000], heap[600000];

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

int a, b, mo;

void modify(int L, int R, int x) {
	if (R - L == 0) {
		heap[x - 1] += mo;
		return;
	}
	int M = (L + R) / 2;
	if (M >= a) {
		modify(L, M, (x << 1));
	}
	if (M < a) {
		modify(M + 1, R, (x << 1) + 1);
	}
	heap[x - 1] += mo;
	return;
}


int ans;

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
	for (int t = 1; scanf("%d", &n), n; t++) {
		if (t>1)printf("\n");
		printf("Case %d:\n", t);
		init();
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		bulit(1, n, 1);
		char ch;
		while (cin >> ch, ch != 'E') {
			scanf("%d %d", &a, &b);
			if (ch == 'S') {
				mo = b - arr[a];
				arr[a] = b;
				modify(1, n, 1);
			}
			else if (ch == 'M') {
				ans = 0;
				quest(1, n, 1);
				printf("%d\n", ans);
			}
		}
		cin >> ch >> ch;
	}
}