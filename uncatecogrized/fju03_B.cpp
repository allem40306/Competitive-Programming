#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 15;
const int M = 2005;

int main() {
	int n, k, c, g;
	vector<int>v[N];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> c >> g;
		v[g].push_back(c);
	}
	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end(), greater<int>());
	}
	int dp[N][M], ans = 0;
	for (int i = 1; i <= 10; i++) {
		int s = 0;
		for (int j = 1; j <= v[i].size(); j++) {
			// cout << i << ' ' << j << ' ' << v[i][j - 1] << '\n';
			s += v[i][j - 1];
			for (int jj = 0; jj + j <= k; jj++) {
				dp[i][jj + j] = max(dp[i][jj + j], dp[i - 1][jj] + s + j * (j - 1));
				ans = max(ans, dp[i][jj + j]);
			}
		}
		for (int j = 0; j <= k; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	cout << ans << '\n';
}
