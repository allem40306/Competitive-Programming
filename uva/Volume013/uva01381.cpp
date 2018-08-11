#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = (1 << 16);
const int M = 12000;
int a[16], p[16];
vector<int>state[M];
LL cnt[N];

bool judge(int x) {
	int count = 0;
	for (int i = 0; i < 16; i++) {
		if (x & (1 << i)) {
			p[count++] = a[i];
		}
	}
	return count == 4;
}

LL sol() {
	LL ans = 0;
	int x;
	for (int i = 1; i < N; i++) {
		if (!judge(i))continue;
		do {
			x = p[0] * 4 + p[1] * 3 + p[2] * 2 + p[3];
			for (auto j : state[x]) {
				if ((i & j) == 0)cnt[i | j]++;
			}
			state[x].push_back(i);
		} while (next_permutation(p, p + 4));
	}
	for (int i = 0; i < N; i++)ans += cnt[i] * cnt[i ^ (N - 1)];
	return ans / 2;
}

int main() {
	int ti = 1;
	while (cin >> a[0], a[0]) {
		for (int i = 1; i < 16; i++)cin >> a[i];
		sort(a, a + 16);
		for (int i = 0; i < M; 	i++)state[i].clear();
		memset(cnt, 0, sizeof(cnt));
		cout << "Case " << ti++ << ": " << sol() << '\n';
	}
}