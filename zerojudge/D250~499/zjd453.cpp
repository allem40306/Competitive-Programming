#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define N 105
#define INF 10000

struct loc{
	int x, y;
	loc(int x, int y) :x(x), y(y){}
}k = loc(0, 0);

int main(){
	int ni=0,n, a, b, x1, x2, y1, y2;
	int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	for (cin >> n;ni<n;ni++){
		cin >> a >> b >> x1 >> y1 >> x2 >> y2;
		string s[N];
		int w[N][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				w[i][j] = INF;
		for (int i = 0; i < a; i++)cin >> s[i];
		queue <loc> q;
		q.push(loc(x1-1, y1-1));
		w[x1 - 1][y1 - 1] = 1;
		while (!q.empty()){
			loc k = q.front(); q.pop();
			for (int i = 0; i < 4; i++){
				int x = k.x + dx[i], y = k.y + dy[i];
				if (x >= 0 && x < a&&y >= 0 && y < b&&w[x][y]==INF&&s[x][y]=='0'){
					w[x][y] = w[k.x][k.y] + 1;
					q.push(loc(x, y));
				}
			}
		}
		if (w[x2 - 1][y2 - 1] != INF)printf("%d\n", w[x2 - 1][y2 - 1]);
		else printf("0\n");
	}
}