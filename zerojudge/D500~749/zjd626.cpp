#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define N 150

struct loc {
	int x, y;
	loc(int x, int y) :x(x), y(y) {}
}k = loc(0, 0);

int main() {
	int n, x, y;
	int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	while (cin >>n) {
		string s[N];
		stack <loc> st;
		for (int i = 0;i < n;i++)cin >> s[i];
		cin >> x >> y;
		st.push(loc(x, y));
		while (!st.empty()) {
			loc k = st.top(); st.pop();
			for (int i = 0;i < 4;i++) {
				x = k.x + dx[i], y = k.y + dy[i];
				if (x >= 0 && x < n&&y >= 0 && y < n&&s[x][y] == '-') {
					st.push(loc(x, y));
					s[x][y] = '+';
				}
			}
		}
		for (int i = 0;i < n;i++)cout << s[i] << endl;
	}
}