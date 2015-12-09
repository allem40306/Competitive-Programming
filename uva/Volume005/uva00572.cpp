#include <iostream>
#include <functional>
#include <stack>
using namespace std;
#define N 100
#define D 8
int dx[D] = { -1, 0, 1, -1, 1, -1, 0, 1, }, dy[D] = { -1, -1, -1, 0, 0, 1, 1, 1, };


struct loc{
	int x, y;
	loc(int x, int y) :x(x), y(y){}
}k = loc(0, 0);

int main(){
	int m, n;
	while (cin >> m >> n, m){
		stack <loc> q;
		char ch[N][N];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> ch[i][j];
		int cas = 0, x = 0, y = 0, cc[N][N] = {};
		for (int ii = 0; ii < m; ii++)
			for (int jj = 0; jj < n; jj++){
			if (cc[ii][jj] || ch[ii][jj] == '*')continue;
			cas++;
			q.push(loc(ii, jj));
			cc[ii][jj] = 1;
			while (!q.empty()){
				k = q.top(); q.pop();
				for (int i2 = 0; i2 < D; i2++){
					x = k.x + dx[i2]; y = k.y + dy[i2];
					//printf_s("(%d,%d)\n", x, y);
					if (0 <= x && x<m && 0 <= y && y<n && ch[x][y] == '@'&&cc[x][y] == 0){
						cc[x][y] = 1;
						q.push(loc(x, y));
					}
				}
			}

			}
		cout << cas << endl;
	}
}
