#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

int arr[300000], heapp[600000], bp;
int two[20] = { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,65536,131072,262144 };

void init() {
	memset(arr, 0, sizeof(arr));
	memset(heapp, -1, sizeof(heapp));
	bp = 0;
}

int bulit(int L, int R, int x) {
	if (R - L == 0) {
		heapp[x - 1] = arr[bp++];
		return heapp[x - 1];
	}
	if (R - L == 1) {
		heapp[x - 1] = bulit(L, L, (x << 1)) + bulit(R, R, (x << 1) + 1);
		return  heapp[x - 1];
	}
	int M = (L + R) / 2;
	heapp[x - 1] = bulit(L, M, (x << 1)) + bulit(M + 1, R, (x << 1) + 1);
	return heapp[x - 1];
}

int a, b, mo;

void modify(int L, int R, int x) {
	if (R - L == 0) {
		heapp[x - 1] += mo;
		return;
	}
	if (R - L == 1) {
		modify(L, L, (x << 1) + (R == a));
		heapp[x - 1] += mo;
		return;
	}
	int M = (L + R) / 2;
	if (M >= a) {
		modify(L, M, (x << 1));
	}
	if (M < a) {
		modify(M + 1, R, (x << 1) + 1);
	}
	heapp[x - 1] += mo;
	return;
}


int ans;

void quest(int L, int R, int x, int m, int n) {
	if (L == m&&R == n) {
		ans += heapp[x - 1];
		return;
	}
	if (R - L == 0) {
		ans += heapp[x - 1];
		return;
	}
	if (R - L == 1) {
		if (m == n)quest(m, m, (x << 1) + (R == m), m, n);
		if (m != n) {
			quest(L, L, (x << 1), m, m);
			quest(R, R, (x << 1) + 1, n, n);
		}
		return;
	}
	int M = (L + R) / 2;
	if (m <= M) {
		if (n < M)quest(L, M, (x << 1), m, n);
		if (n >= M)quest(L, M, (x << 1), m, M);
	}
	if (n >= M + 1) {
		if (m <= M + 1)quest(M + 1, R, (x << 1) + 1, M + 1, n);
		if (m > M + 1)quest(M + 1, R, (x << 1) + 1, m, n);
	}
	return;
}

int main() {
	int n, t = 0;
	while (scanf("%d", &n), n) {
		if (t)printf("\n");
		printf("Case %d:\n", ++t);
		init();
		for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
		int tp = 0;
		while (two[tp] < n)tp++;
		//memset(heapp, 0, sizeof(heapp));
		bulit(1, two[tp], 1);
		char ch;
		while (cin >> ch, ch != 'E') {
			scanf("%d %d", &a, &b);
			if (ch == 'S') {
				mo = b - arr[a - 1];
				arr[a - 1] = b;
				modify(1, two[tp], 1);

			}
			else if (ch == 'M') {
				ans = 0;
				quest(1, two[tp], 1, a, b);
				printf("%d\n", ans);
			}
		}
		cin >> ch >> ch;
	}
}