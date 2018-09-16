#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	while (cin >> s, s != "0") {
		long long x = 0, y = 1;
		bool ok = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') {
				ok = 1;
				continue;
			}
			x = x * 10 + (s[i] - '0');
			if (ok)y *= 10;
		}
		long long tmp = __gcd(x, y);
		cout << x / tmp << '/' << y / tmp << '\n';
	}
}
