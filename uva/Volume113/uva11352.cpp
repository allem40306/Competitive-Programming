#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define N 200
#define M 8
int dax[M] = { -1, -2, -2, -1, 1, 2, 2, 1 }, day[N] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dbx[M] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dby[N] = { -1, 0, 1, -1, 1, -1, 0, 1 };

struct loc{
	int x, y;
	loc(int x, int y) :x(x), y(y){}
}k = loc(0, 0);

int main() {
	int t, n, m;
	cin >> t;
	while (t--){
		string s[N];
		queue <loc> q;
		int a[N][N] = {};
		cin >> n >> m >> ws;
		int ax, ay, bx, by;
		for (int i = 0; i < n; i++)getline(cin, s[i]);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (s[i][j] == 'Z'){ a[i][j] = -1; q.push(loc(i, j)); }
				else if (s[i][j] == 'A')ax = i, ay = j;
				else if (s[i][j] == 'B')bx = i, by = j;
			}
		}
		while (!q.empty()){
			k = q.front(); q.pop();
			for (int i2 = 0; i2 < M; i2++){
				int x = k.x + dax[i2], y = k.y + day[i2];
				if (x >= 0 && x<n && y >= 0 && y<m &&s[x][y] != 'Z'&& !a[x][y]){
					a[x][y] = -1;
				}
			}
		}
		int ans = 0;
		a[ax][ay] = a[bx][by] = 0;
		q.push(loc(ax, ay));
		while (!q.empty()){
			k = q.front(); q.pop();
			for (int i2 = 0; i2 < M; i2++){
				int x = k.x + dbx[i2], y = k.y + dby[i2];
				if (x >= 0 && x<n && y >= 0 && y<m &&a[x][y] == 0){
					a[x][y] = a[k.x][k.y] + 1;
					if (x == bx&&y == by)ans = (ans>a[x][y] ? ans : a[x][y]);
					q.push(loc(x, y));
				}
			}
		}
		if (ans)printf("Minimal possible length of a trip is %d\n", ans);
		else printf("King Peter, you can't go now!\n");
	}
}