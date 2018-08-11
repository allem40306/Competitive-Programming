
#include <bits/stdc++.h>
using namespace std;

int ch_to_base(char ch) {
	if (ch <= '9') return ch - '0';
	if (ch <= 'Z') return ch - 'A' + 10;
	return ch - 'a' + 36;
}

int main() {
	string s;
	int b, sum;
	bool ans;
	while (cin >> s) {
		b = 1; sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (isalnum(s[i])) {
				int bb = ch_to_base(s[i]);
				b = max(b, bb);
				sum += bb;
			}
		}
		ans = 0;
		for (int i = b; i <= 62; i++) {
			if (sum % i == 0) {
				cout << i+1 << '\n';
				ans = 1;
				break;
			}
		}
		if (!ans)cout << "such number is impossible!\n";
	}
}
