#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 100000000;
vector<LL>f;

void build() {
	f.push_back(1);
	f.push_back(2);
	for (int i = 2;; i++) {
		f.push_back(f[i - 1] + f[i - 2]);
		if (f[i] > N)return;;
	}
}

void sol(LL n) {
	bool b = 0;
	for (int i = f.size() - 1; i >= 0; i--) {
		if (n >= f[i])b = 1;
		if (b)cout << (n >= f[i]);
		if (n >= f[i])n -= f[i];
	}
	return;
}

int main() {
	int t;
	LL n;
	build();
	cin >> t;
	while (t--) {
		cin >> n;
		cout << n << " = ";
		sol(n);
		cout << " (fib)\n";
	}
}