#include <iostream>
#include <algorithm>
using namespace std;
#define N 500005
static int n, q, qq, a[N];

int bf(int n, int L, int R) {
	int M = (L + R) >> 1;
	if (n < a[L])return L;
	if (n >= a[R])return R + 1;
	if (n < a[M])return bf(n, L, M);
	return bf(n, M + 1, R);
}

int main() {
	while (cin >> n >> q) {
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < q; i++) {
			cin >> qq;
			printf("%d\n", bf(qq, 0, n - 1) % 2);
		}
	}
}