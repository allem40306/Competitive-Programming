#include <iostream>
using namespace std;
#define N 60000
int main(){
	int n, k;
	while (cin >> n >> k){
		int m, sum = 0, dp[N] = {}, a[N], ar = 0;
		for (int i = 0; i < n; i++){
			cin >> m;
			if (m > k)continue;
			sum += m;
			a[ar++] = m;
		}
		for (int i = 0; i < ar; i++){
			for (int j = sum; j - a[i] >= 0; j--){
				if (dp[j - a[i]]+a[i]>dp[j] && dp[j - a[i]] + a[i] <= sum)
					dp[j] = dp[j - a[i]] + a[i];
			}
		}
		for (int i = sum / 2; i >= 0; i--){
			if (dp[i] == i){
				printf("%d %d\n", i, sum - i);
				break;
			}
		}
	}
}