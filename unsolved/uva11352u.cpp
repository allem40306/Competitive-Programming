#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define N 200
#define M 8
int da[M][2] = { (-1, -2), (-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2) };
int db[M][2] = { (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1) };

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
		int a[N][N] = {}, b[N][N] = {};
		cin >> n >> m >> ws;
		int ax, ay, bx, by;
		for (int i = 0; i < n; i++)getline(cin,s[i]);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (s[i][j] == 'Z')q.push(loc(i, j));
				else if (s[i][j] == 'A')ax = i, ay = j;
				else if (s[i][j] == 'B')bx = i, by = j;
			}
		}	
		while (!q.empty()){
			k = q.front(); q.pop();
			for (int i2 = 0; i2 < M; i2++){
				int x = k.x + da[i2][0], y = k.y + da[i2][1];
				if (x >= 0&&x<n && y >= 0&&y<n &&s[x][y]!='Z'&& !a[x][y]){
					a[x][y] = a[k.x][k.y]+1;
					q.push(loc(x, y));
				}
			}
		}
		q.push(loc(ax, ay));
		int ans = 0;
		while (!q.empty()){
			k = q.front(); q.pop();
			for (int i2 = 0; i2 < M; i2++){
				int x = k.x + db[i2][0], y = k.y + db[i2][1];
				if (x >= 0 && x<n && y >= 0 && y<n && b[x][y]<a[x][y]){
					a[x][y] = a[k.x][k.y] + 1;
					if (x == bx&&y == by)ans = (ans>b[x][y] ? ans : b[x][y]);
					q.push(loc(x, y));
				}
			}
		}
		if (ans)printf("Minimal possible length of a trip is %d\n", ans);
		else printf("King Peter, you can't go now!\n");
	}
}