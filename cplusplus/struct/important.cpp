#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
#define scanf scanf_s
int arr[1010], heapp[600000];
int bp = 0;

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
	if (R - L <= 1) {
		mo = b - heapp[x - (a == L) - 1];
		heapp[x - (a == L) - 1] += mo;
		return;
	}
	int M = (L + R) / 2;
	if (M > a) {
		modify(L, M, (x << 1));
	}
	if (M <= a) {
		modify(M, R, (x << 1) + 1);
	}
	heapp[x - 1] = heapp[(x << 1) - 1] + heapp[(x << 1)];
	return;
}

int ans;

void quest(int L, int R, int x) {
	if (R - L == 0) {
		ans += heapp[x - 1];
		return;
	}
	if (R - L == 1) {
		ans += heapp[x - 1] + heapp[x];
	}
	int M = (L + R) / 2;
	if (a == L&&b == M) {
		ans += heapp[(x << 1) - 1];
		return;
	}
	if (a == M + 1 && b == R) {
		ans += heapp[(x << 1)];
		return;
	}
	if (a < M) {
		quest(a, M, (x << 1));
	}
	if (b > M + 1) {
		quest(M + 1, b, (x << 1) + 1);
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
		int bp = 0;
		bulit(1, n, 1);
		int s; //string s;
		while (cin >> s, s) {
			cin >> a >> b;
			if (s == 1) { //§ï¹D³o
				modify(0, n, 1);
				a--;
			}
			else if (s == 2) {
				ans = 0;
				quest(0, n, 1);
				printf("%d\n");
			}
		}
	}
}