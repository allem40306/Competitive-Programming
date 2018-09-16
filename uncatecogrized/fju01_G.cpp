#include <iostream>
using namespace std;
const int N = 105;
struct Loc {
	int x, y;
};
string st[N];
int n, m;
int dy[4] = { -1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
bool road(int x, int y) {
	// cout << x << '_' << y << '\n';
	if (x < 0 || y < 0 || x >= n || y >= m || st[x][y] == 'X')return 0;
	return 1;
}
bool cango(int x, int y) {
	for (int i = 0; i < 4; i++) {
		if (road(x + dx[i], y + dy[i]))return 1;
	}
	return 0;
}
int main() {
	int s;
	Loc A, B;
	cin >> n >> m >> s;
	s--;
	for (int i = 0; i < n; i++) {
		cin >> st[i];
		for (int j = 0; j < m; j++) {
			if (st[i][j] == 'A') {A.x = i; A.y = j;}
			else if (st[i][j] == 'B') {B.x = i; B.y = j;}
		}
	}
	if (!cango(A.x, A.y)) {
		cout << "-1\n";
		return 0;
	}
	int ans = 0, nx = A.x, ny = A.y;
	bool vis[N][N][5] = {};
	while (1) {
		// cout << nx << ' ' << ny << ' ' << s << '\n';
		vis[nx][ny][s] = 1;
		if (road(nx + dx[(s + 3) % 4], ny + dy[(s + 3) % 4])) {
			// cout<<"left\n";
			ans++;
			s = (s + 3) % 4;
			nx += dx[s];
			ny += dy[s];
		} else if (road(nx + dx[s], ny + dy[s])) {
			// cout<<"stright\n";
			ans++;
			nx += dx[s];
			ny += dy[s];
		} else {
			s = (s + 1) % 4;
		}
		if (vis[nx][ny][s]) {
			cout << "-1\n";
			break;
		}
		if (nx == B.x && ny == B.y) {
			cout << ans << '\n';
			break;
		}
	}
}
