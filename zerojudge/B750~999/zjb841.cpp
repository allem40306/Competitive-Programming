#include <iostream>
using namespace std;
#define N 10
int h, w, a[N][N], vis[N][N], ans;
int dx[2] = { 1, 0 }, dy[2] = { 0, 1 };

void dp(int x, int y, int p){
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			for (int k = 0; k < 2; k++){
		int r = i + dx[k], s = j + dy[k];
		if (!vis[i][j] && r < h&&s < w&& !vis[r][s] && a[i][j] == a[r][s]){
			p++; ans = ans > p ? ans : p;
			vis[i][j] = vis[r][s] = 1;
			dp(r, s, p);
			vis[i][j] = vis[r][s] = 0;
			p--;
		}
			}
	return;
}

int main() {
	while (cin >> h >> w){
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a[i][j] = vis[i][j] = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> a[i][j];
		ans = 0;
		dp(0, 0, 0);
		printf("%d\n", ans);
	}
}