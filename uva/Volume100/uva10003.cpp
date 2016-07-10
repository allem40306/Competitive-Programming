#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
#define N 55

int minCutCost(int c[], int dp[][N], int l, int u){
	if (dp[l][u] != -1)return dp[l][u];
	if (l == u - 1)return dp[l][u] = 0;
	dp[l][u] = INT_MAX;
	for (int i = l + 1; i < u; ++i){
		dp[l][u] = min(dp[l][u], minCutCost(c, dp, l, i) +
			minCutCost(c, dp, i, u) + (c[u] - c[l]));
	}
	return dp[l][u];
}

int main(){
	int ll, n;
	while (cin >> ll, ll){
		int c[N], dp[N][N];
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> c[i];
		c[0] = 0, c[n + 1] = ll;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dp[i][j] = -1;
		printf("The minimum cutting is %d.\n", minCutCost(c, dp, 0, n + 1));
	}
}