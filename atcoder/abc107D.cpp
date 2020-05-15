#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long LL;
#define lowbit(x) (x&(-x))
LL n;
LL a[N], b[N], bit[4 * N];

void add(LL x, LL val) {
	x += n + 1;
	for (; x <= 2 * n + 1; x += lowbit(x)) {
		bit[x] += val;
	}
}

LL sum(LL x) {
	LL val = 0;
	x += n + 1;
	for (; x > 0; x -= lowbit(x)) {
		val += bit[x];
	}
	return val;
}

LL sol(LL x) {
	LL tmp = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x) {
			tmp++;
		} else {
			tmp--;
		}
		ans += sum(tmp - 1);
		add(tmp, 1);
	}
	tmp = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x) {
			tmp++;
		} else {
			tmp--;
		}
		add(tmp, -1);
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	memset(bit, 0, sizeof(bit));
	sort(b, b + n);
	LL nn = unique(b + 1, b + 1 + n) - b - 1;
	LL L = 1, R = nn, M, ans;
	LL tar = (n * (n + 1) / 2) / 2 + 1;
	add(0, 1);
	while (L <= R) {
		M = (L + R) >> 1;
		LL res = sol(b[M]);
		if (res >= tar) {
			ans = b[M];
			R = M - 1;
		} else {
			L = M + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
