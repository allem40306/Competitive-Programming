#include <bits/stdc++.h>
using namespace std;
const int N = 105;
long long a[N][N];

bool sol(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (a[i][j] != a[n - 1 - i][n - 1 - j])return 0;
		}
	}
	return 1;
}

int main() {
	int t, n;
	char ch;
	bool p;//postive
	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		p = 1;
		cin >> ch >> ch >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] < 0)p = 0;
			}
		}
		cout << "Test #" << ti << ": " << (p && sol(n) ? "Symmetric.\n" : "Non-symmetric.\n");
	}
}
