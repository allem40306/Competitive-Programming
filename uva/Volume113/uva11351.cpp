#include <iostream>
using namespace std;


int main() {
	int t, k, n;
	cin >> t;
	for (int ti = 0; ti < t; ti++){
		cin >> n >> k;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = (ans + k) % i;
		printf("Case %d: %d\n", ti+1, ans+1);
	}
}