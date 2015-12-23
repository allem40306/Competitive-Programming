#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
#define scanf scanf_s
int arr[20010], heapp[600000];
int bp = 0;
int two[15] = { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
int bulit(int L, int R, int x) {
	if (R - L == 0) {
		heapp[x - 1] = arr[bp++];
		return heapp[x - 1];
	}
	int M = (L + R) / 2;
	heapp[x - 1] = bulit(L, M, (x << 1)) + bulit(M + 1, R, (x << 1) + 1);
	return heapp[x - 1];
}

int a, b, mo;

void modify(int L, int R, int x) {
	if (R - L == 0) {
		mo = b - heapp[x - (a == L) - 1];
		heapp[x - 1] += mo;
		return;
	}
	if (R - L == 1){
		modify(L, L, (x << 1) + (R == a));
		heapp[x - 1] += mo;
		return;
	}
	int M = (L + R) / 2;
	if (M >= a) {
		modify(L, M, (x << 1));
	}
	if (M < a) {
		modify(M, R, (x << 1) + 1);
	}
	heapp[x - 1] += mo;
	return;
}


int ans;

void quest(int L, int R, int x, int m, int n) {
	if (R - L == 0) {
		ans += heapp[x - 1];
		return;
	}
	if (R - L == 1 && m == n) {
		quest(L, L, (x << 1) + (R == m), m, n);
		return;
	}
	if (L == m&&R == n){
		ans += heapp[x - 1];
		return;
	}
	int M = (L + R) / 2;
	if (m <= M){
		if (n <= M)quest(L, M, (x << 1), m, n);
		if (n>M)quest(L, M, (x << 1), m, M);
	}
	if (n > M){
		if (m<M)quest(M + 1, R, (x << 1) + 1, M + 1, n);
		if (m >= M)quest(M + 1, R, (x << 1) + 1, m, n);
	}
	return;
}

int main() {
	int n, t = 0;

	while (scanf("%d", &n), n) {
		if (t)printf("\n");
		printf("Case %d:\n", ++t);
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
		int tp = 0;
		while (two[tp] < n)tp++;
		//memset(heapp, 0, sizeof(heapp));
		bulit(1, two[tp++], 1);
		char ch;
		while (cin >> ch, ch != 'E') {
			scanf("%d %d", &a, &b);
			if (ch == 'S') {
				modify(1, two[tp++], 1);
			}
			else if (ch == 'M') {
				ans = 0;
				quest(1, n, 1, a, b);
				printf("%d\n", ans);
			}
		}
		cin >> ch >> ch;
	}
}