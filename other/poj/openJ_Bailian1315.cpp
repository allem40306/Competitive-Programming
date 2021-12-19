#include <iostream>
#include <string>
using namespace std;
#define N 100
int vis[N][N], n, mmax;
int d[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
string s[N];

bool isok(int i, int j){
	for (int a = 0; a < 4; a++){
		int dx = i+d[a][0], dy = j+d[a][1];
		while (dy >= 0 && dy < n&&dx >= 0 && dx < n){
			if (s[dx][dy] == 'X')break;
			if (vis[dx][dy])return false;
			dx += d[a][0], dy += d[a][1];
		}
	}
	return true;
}

void search(int cur){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			if (!vis[i][j] && s[i][j] != 'X'&&isok(i, j)){
				vis[i][j] = 1;
				search(cur + 1);
				vis[i][j] = 0;
			}
		}
	}
	if (cur>mmax)mmax = cur;
	return;
}

int main(){
	while (cin >> n, n){
		mmax = 0;
		for (int i = 0; i < n; i++)cin >> s[i];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				vis[i][j] = 0;
 		search(0);
		printf("%d\n", mmax);
	}
}
