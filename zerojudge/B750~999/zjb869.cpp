#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;
#define N 50010


int main() {
	int n, dp[N], ans;
	string s, t = "rgb";
	while (cin >> n) {
		cin >> s;
		memset(dp, 0, sizeof(dp));
		ans = 1;
		for (int i = 0; i < 3; i++) {
			for (int ii = 1; ii <= n; ii++)
				dp[ii] = (s[ii-1] == t[i] ? dp[ii - 1] + 1 : max(dp[ii], dp[ii - 1]));
		}
		printf("%d\n", dp[n]);
	}
}