#include <iostream>
#include <cstring>
using namespace std;
#define N 100005

int main() {
	int t, n, a[N], ti = 0;
	bool dp[N];
	for (cin >> t; ti < t; ti++) {
		int sum = 0;
		cin >> n;
		for (int ni = 0; ni < n; ni++) {
			cin >> a[ni]; sum += a[ni];
		}
		memset(dp, false, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = sum; j - a[i] >= 0; j--) {
				if (dp[j - a[i]])dp[j] = true;
			}
		}
		for (int k = sum / 2 + (sum % 2);; k++) {
			if (dp[k]) {
				cout << k << endl; break;
			}
		}
	}
}