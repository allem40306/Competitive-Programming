#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define N 2000001

int main(){
	int n;
	while (cin >> n){
		long long sum = 0, a[N], c[N], ave;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			sum += a[i];
		}
		ave = sum / n;
		c[0] = 0;
		for (int i = 1; i <= n; i++)
			c[i] = c[i - 1] + a[i] - ave;
		sort(c+1, c + n+1);
		long long x = c[(n + 1) / 2];
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans += abs(c[i] - x);
		printf("%lld\n", ans);
	}
}