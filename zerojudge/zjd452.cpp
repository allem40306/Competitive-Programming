#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, i = 0;
	for (cin >> n; i < n; i++){
		int a[200] = {};
		cin >> m;
		for (int j = 0; j < m; j++)cin >> a[j];
		sort(a, a + m);
		int ans = 0;
		for (int k = 0; k < m; k++)
			ans += (abs(a[m/2] - a[k]));
		printf("%d\n", ans);
	}
}