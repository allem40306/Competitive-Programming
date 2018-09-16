#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1005;
const int M = 8;
int dx[M] = { -3, -3, -1, 1, 3, 3, 1, -1}, dy[M] = {1, -1, -3, -3, -1, 1, 3, 3};
int qx[M] = { -1, 0, 1, 0}, qy[M] = {0, -1, 0, 1};
struct Loc {
	int x, y;
	Loc() {};
	Loc(int x, int y): x(x), y(y) {}
};

int main() {
	static int n, ans[N][N];
	Loc a[N], s, t;
	cin >> n;
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		ans[a[i].x][a[i].y] = -2;
	}
	cin >> s.x >> s.y >> t.x >> t.y;
	queue<Loc>q;
	q.push(s);
	ans[s.x][s.y] = 0;
	while (!q.empty()) {
		Loc k = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = k.x + qx[i], yy = k.y + qy[i];
			// cout << xx << '_' << yy << '\n';
			if (xx < 0 || xx > 99 || yy < 0 || yy > 99 || ans[xx][yy] == -2)continue;
			for (int j = 0; j <= 1; j++) {
				xx = k.x + dx[2 * i + j]; yy = k.y + dy[2 * i + j];
				// cout << xx << '=' << yy << '\n';
				if (xx < 0 || xx > 99 || yy < 0 || yy > 99 || ans[xx][yy] != -1)continue;
				ans[xx][yy] = ans[k.x][k.y] + 1;
				q.push(Loc(xx, yy));
			}
		}
	}
	if (ans[t.x][t.y] <= 0)cout << "impossible\n";
	else cout << ans[t.x][t.y] << '\n';
}
