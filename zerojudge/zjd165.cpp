#include <iostream>
#include <functional>
#include <stack>
using namespace std;
#define N 100
#define D 4
int dx[D] = { 0, -1, 1, 0 }, dy[D] = { -1, 0, 0, 1 };
#define max(x,y) x>y?x:y


struct loc{
	int x, y;
	loc(int x, int y) :x(x), y(y){}
}k = loc(0, 0);

int main(){
	int m, n;
	while (cin >> m >> n){
		stack <loc> q;
		int ii[N][N], jj[N][N];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++){
			cin >> ii[i][j];
			jj[i][j] = 1;
			}

		int ans = 0, ans2 = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++){
			if (ii[i][j] && jj[i][j]){
				ans2++;
				int tot = ii[i][j];
				q.push(loc(i, j));
				jj[i][j] = 0;
				while (!q.empty()){
					k = q.top(); q.pop();
					for (int i2 = 0; i2 < D; i2++){
						int x = k.x + dx[i2], y = k.y + dy[i2];
						if (0 <= x && x < m && 0 <= y && y < n && ii[x][y] && jj[x][y]){
							tot += ii[x][y];
							jj[x][y] = 0;
							q.push(loc(x, y));
						}
					}
				}
				ans = max(ans, tot);
			}
		}
		printf("%d\n%d\n", ans2, ans);
	}
}