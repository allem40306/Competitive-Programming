#include <iostream>
using namespace std;
const int N = 1000005;

int main() {
	static int n, m, a[N] = {}, q;
	string s;
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		a[i + 1] = a[i] + 1 + (s[i] == 'T');
	}
	for (int i = 0; i < m; i++) {
		cin >> q;
		bool ok = 0;
		for (int j = 1, k = 1;;) {
			int sum = a[k] - a[j - 1];
			if (sum == q) {
				cout << j << ' ' << k << '\n';
				ok = 1;
				break;
			} else if (sum < q) {
				k++;
			} else {
				j++;
			}
			if (k == n) {
				break;
			}
		}
		if (!ok)cout << "NIE\n";
	}
}
