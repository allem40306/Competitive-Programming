#include <iostream>
using namespace std;
#define N 20

int main() {
	int n, nn = 1;
	while (cin >> n){
		int a[N][2];
		long ans = 0;
		a[0][0] = 1, a[0][1] = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i][0];
			a[i][1] = 0;
			if (a[i][0] < 0){ a[i][1]++; a[i][0] *= -1; }
			a[i][1] += a[i-1][1];
		}
		for (int j = 1; j <= n; j++)
			for (int k = j; k <= n; k++){
			if ((a[k][1] - a[j - 1][1]) % 2 == 0){
				long ans2 = 1;
				for (int m = j; m <= k; m++)ans2 *= a[m][0];
				ans = (ans2 < ans ? ans : ans2);
			}
		}
		printf("Case #%d: The maximum product is %ld.\n\n", nn++, ans);
	}
}