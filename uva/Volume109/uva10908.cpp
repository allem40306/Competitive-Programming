#include <bits/stdc++.h>
using namespace std;
const int N = 105;
string s[N];
int m, n;

bool sol(int x, int y, int d) {
	if (x - d < 0 || x + d >= m || y - d < 0 || y + d >= n)return 0;
	char ch = s[x][y];
	for (int i = 0; i <= 2 * d; i++) {
		if (ch != s[x - d + i][y - d])return 0;
		if (ch != s[x - d][y - d + i])return 0;
		if (ch != s[x + d - i][y + d])return 0;
		if (ch != s[x + d][y + d - i])return 0;
	}
	return 1;
}

int main() {
	int t, q, x, y;
	cin >> t;
	while (t--) {
		cin >> m >> n >> q;
		cout << m << ' ' << n << ' ' << q << '\n';
		for (int i = 0; i < m; i++)cin >> s[i];
		for (int i = 0; i < q; i++) {
			cin >> x >> y;
			for (int ans = 1;; ans++) {
				if (!sol(x, y, ans)) {
					cout << 2 * ans - 1 << '\n';
					break;
				}
			}
		}
	}
}