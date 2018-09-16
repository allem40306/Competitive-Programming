#include <iostream>
using namespace std;
const int N = 105;

int main() {
	int n, m, r[N] = {}, c[N] = {};
	string s[N];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') {
				r[i]++;
				c[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!r[i])continue;
		for (int j = 0; j < m; j++) {
			if (!c[j])continue;
			cout << s[i][j];
		}
		cout << '\n';
	}
}
