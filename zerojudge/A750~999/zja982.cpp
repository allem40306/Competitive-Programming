#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define N 105
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

struct loc{
	int x, y;
	loc(int x, int y) :x(x), y(y){}
}k = loc(0, 0);

int main(){
	int n, x, y;
	while (cin >> n){
		int w[N][N] = { 0 }, vis[N][N] = { 0 };
		string s[N];
		for (int i = 0; i < n; i++)cin >> s[i];
		queue <loc> q;
		q.push(loc(1, 1));
		vis[1][1] = 1;
		w[1][1] = 1;
		while (!q.empty()){
			k = q.front(); q.pop();
			for (int i2 = 0; i2 < 4; i2++){
				x = k.x + dx[i2]; y = k.y + dy[i2];
				if (x>=0&&x<n&&y>=0&&y<n&&!vis[x][y]&&s[x][y]=='.'){
					vis[x][y] = 1;
					w[x][y] = w[k.x][k.y]+1;
					q.push(loc(x, y));
				}
			}
		}	
		if(w[n - 2][n - 2])printf("%d\n", w[n - 2][n - 2]);
		else printf("No solution!\n");
	}
}
