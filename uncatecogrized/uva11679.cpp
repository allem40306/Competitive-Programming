#include <bits/stdc++.h>
using namespace std;
const int N = 50;

int main() {
	int b, n, r[N];
	while (cin >> b >> n, b || n) {
		for (int i = 1; i <= b; i++) {
			cin >> r[i];
		}
		int d, c, v;
		for (int i = 0; i < n; i++) {
			cin >> d >> c >> v;
			r[d] -= v;
			r[c] += v;
		}
		bool ok = 1;
		for (int i = 1; i <= b; i++) {
			if (r[i] < 0)ok = 0;
		}
		cout << (ok ? "S\n" : "N\n");
	}
}
