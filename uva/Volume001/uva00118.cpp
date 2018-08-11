#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int dx[4] = {0, 1, 0, -1}, dy[4] = { 1, 0, -1, 0};
bool Map[N][N] = {};
string sd = "NESW";
int main() {
	int n, m, x, y, d;
	char ch;
	string s;
	cin >> n >> m;
	while (cin >> x >> y >> ch >> s) {
		bool lost = 0;
		d = sd.find(ch);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'F') {
				x += dx[d];
				y += dy[d];
				if (x < 0 || x > n || y < 0 || y > m) {
					x -= dx[d];
					y -= dy[d];
					if (Map[x][y])continue;
					Map[x][y] = 1;
					lost = 1;
					break;
				}
			} else if (s[i] == 'L') {
				d = (d + 3) % 4;
			} else {
				d = (d + 1) % 4;
			}
			// cout << x << '-' << y << ' ' << sd[d] << '\n';
		}
		cout << x << ' ' << y << ' ' << sd[d];
		if (lost) {
			cout << " LOST";
		}
		cout << '\n';
	}
}