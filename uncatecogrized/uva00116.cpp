#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int main(int argc, char const *argv[]) {
	int n, m, a[N][N], dp[N][N], next[N][N];
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				dp[i][j] = a[i][j];
			}
		}
		for (int j = m - 2; j >= 0; j--) {
			for (int i = 0; i < n; i++) {
				int U = a[i][j] + dp[(i - 1 + n) % n][j + 1];
				int H = a[i][j] + dp[i][j + 1];
				int D = a[i][j] + dp[(i + 1) % n][j + 1];
				next[i][j] = 200;
				if (U <= H && U <= D) {
					dp[i][j] = U;
					next[i][j] = min(next[i][j], (i - 1 + n) % n);
				}
				if (H <= D && H <= U) {
					dp[i][j] = H;
					next[i][j] = min(next[i][j], i);
				}
				if (D <= H && D <= U) {
					dp[i][j] = D;
					next[i][j] = min(next[i][j], (i + 1) % n);
				}
				// printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
			}
		}
		int ans = dp[0][0], ans_pos = 0;
		for (int i = 0; i < n; i++) {
			if (ans > dp[i][0]) {
				ans = dp[i][0];
				ans_pos = i;
			}
		}
		int pos = ans_pos;
		cout << pos + 1;
		for (int i = 0; i < m - 1; i++) {
			cout << ' ' << next[pos][i] + 1;
			pos = next[pos][i];
		}
		cout << '\n' << ans << '\n';
	}
	return 0;
}