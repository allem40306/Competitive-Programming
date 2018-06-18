#include <cstdio>
#include <algorithm>
#define N 105
int n, a[N][N], dp[N][N];

int main(){
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i<n; i++)
			for (int j = 0; j < n; j++){
				scanf("%d", &a[i][j]);
				dp[i][j] = a[i][j];
			}
		for (int i = n - 1; i >= 0; i--)
			for (int j = n - 1; j >= 0; j--){
			if (i + 1 < n)dp[i][j] = std::max(dp[i][j], a[i][j] + dp[i + 1][j]);
			if (j + 1 < n)dp[i][j] = std::max(dp[i][j], a[i][j] + dp[i][j+1]);
			}
		printf("%d\n", dp[0][0]);
	}
}
