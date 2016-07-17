#include <iostream>
using namespace std;
#define M 15
#define N 1000000

int main() {
	int n, m;
	while (cin >> n >> m){
		int a[M] = {}, dp[N] = { 0 };
		for (int i = 0; i < m; i++)cin >> a[i];
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < m; j++){
				if (i - a[j] >= 0 && !dp[i - a[j]])
					dp[i] = 1;
			}
		}
		if (dp[n])printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
}