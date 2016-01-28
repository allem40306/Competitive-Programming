#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 10010;
int dp[MAXN];
int tim[25];
bool f[25][MAXN];

int main() {
	int w, n;
	while (cin >> w) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		memset(f, false, sizeof(f));
		for (int i = 1; i <= n; ++i)
			cin >> tim[i];
		for (int i = n; i >= 1; --i)
			for (int v = w; v >= tim[i]; --v)
				if (dp[v] < dp[v - tim[i]] + tim[i])
					dp[v] = dp[v - tim[i]] + tim[i], f[i][v] = true;
		for (int i = 1, j = w; i <= n; ++i)
			if (f[i][j])
				printf("%d ", tim[i]), j -= tim[i];
		printf("sum:%d\n", dp[w]);
	}
	return 0;
}