#include <iostream>
#include <cstring>
using namespace std;
#define N 20

int main() {
	static int dp[N][N], f[N];
	memset(dp, 0, sizeof(dp));
	memset(f, 0, sizeof(f));
	dp[0][0] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j <= i; j++){
		dp[i][j] = (dp[i - 1][j - 1] * j + dp[i - 1][j] * j);
		f[i] = (f[i] + dp[i][j]);
		}
	int t, n, ti = 1;
	for (cin >> t; ti <= t; ti++){
		cin >> n;
		printf("%d\n", f[n]);
	}
}