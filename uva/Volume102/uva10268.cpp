#include <bits/stdc++.h>
using namespace std;
const int N = 2000000;

int main() {
	long long x, a[N], ai, v, y;
	string s;
	while (cin >> x >> ws) {
		ai = 0;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> a[ai])ai++;
		v = 0; y = 1;
		for (int i = ai - 2; i >= 0; i--) {
			v += (ai - i - 1) * a[i] * y;
			y *= x;
		}
		cout << v << '\n';
	}
}