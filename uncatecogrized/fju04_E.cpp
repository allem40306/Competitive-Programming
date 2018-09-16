#include <iostream>
using namespace std;
const long long Mod = 10000019;
const int N = 100005;

int main() {
	static long long dp[N][2], s[N];
	dp[0][0] = 1; dp[0][1] = 0;
	dp[1][0] = 1; dp[1][1] = 0;
	s[0] = 1; s[1] = 2;
	for (int i = 2; i < N; i++) {
		dp[i][0] = s[i - 2] % Mod;
		dp[i][1] = dp[i - 1][0] % Mod;
		s[i] = (s[i - 1] + dp[i][0] + dp[i][1]) % Mod;
	}
	int n;
	cin >> n;
	cout << s[n] % Mod;
}
