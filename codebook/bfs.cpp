#include <iostream>
#include <queue>
using namespace std;

struct loc{
	int x, y;
	loc(int x, int y) :x(x), y(y){}
}k = loc(0, 0);

int main(){
	int m, n, s, s1, p, x, y, cas=0;
	int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	while (cin >> s >> n >> m){
		int w[100][100] = { 0 };
		queue <loc> q;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> w[i][j];
		for (int j1 = 0; j1 < m; j1++)
			if (w[0][j1] == 1){ q.push(loc(0, j1)); break; }
		s1 = s - 1;
		while (!q.empty()){
			k = q.front(); q.pop();
			for (int i2 = s1; i2 < 4; i2++){
				x = k.x + dx[i2]; y = k.y + dy[i2];
				if (x >= 1 && y >= 0 && w[x][y] ==1){
					w[x][y] += w[k.x][k.y];
					q.push(loc(x, y));
				}
			}
		}
		cout << "Case " << ++cas << ":\n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
			cout << w[i][j]<<" ";
			cout << endl;
			}
	}
}