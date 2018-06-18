#include <iostream>
using namespace std;
#define M 20001

int max(int x, int y) {
	if (x > y)return x;
	return y;
}

int main() {
	int v, n;
	while (cin >> v >> n) {
		int nn, dp[M] = {};
		for (int i = 0;i < n;i++) {
			cin >> nn;
			for (int j = v - nn;j>=0;j--)
				dp[j + nn] = max(dp[j + nn], dp[j] + nn);
		}
		int mmax = 0;
		for (int k = 0;k <= v;k++)
			mmax = max(mmax, dp[k]);
		cout << v - mmax << endl;
	}
}