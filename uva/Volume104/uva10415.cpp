#include <bits/stdc++.h>
using namespace std;
#define B(x) ((1<<(x+1))-1)
int press[20] = {B(3) - B(1), B(2) - B(1), B(10) - B(6) + B(4) - B(1), B(9) - B(6) + B(4) - B(1), B(8) - B(6) + B(4) - B(1), B(7) - B(6) + B(4) - B(1), B(4) - B(1)};

int main() {
	for (int i = 7; i < 14; i++) {press[i] = press[i - 7] + 2;}
	press[9] = 8;
	int t, ans[15];
	string s;
	cin >> t;
	getline(cin, s);
	while (t--) {
		getline(cin, s);
		memset(ans, 0, sizeof(ans));
		int state = 0;
		for (int i = 0; i < s.size(); i++) {
			int next = press[(islower(s[i]) ? s[i] - 'a' : s[i] - 'A' + 7)];
			for (int i = 1; i <= 10; i++) {
				ans[i] += (state >> i & 1) == 0 && (next >> i & 1);
			}
			state = next;
		}
		for (int i = 1; i <= 10; i++) {
			if (i != 1)cout << ' ';
			cout << ans[i];
		}
		cout << '\n';
	}
}