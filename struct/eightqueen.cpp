#include <iostream>
#include <iomanip>
using namespace std;
#define N 100
int vis[N][N], c[N], n, to;

void search(int cur){
	if (cur == n){
		to++;
		for (int i = 0; i < n; i++){
			printf("(%d %d)",i, c[i]);
			if (n - i>1)printf(" ");
		}
		cout << endl;
		return;
	}
	else for (int i = 0; i < n; i++) {
		if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]){
			c[cur] = i;
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
			search(cur + 1);
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
		}
	}
	return;
}

int main(){
	n = 8, to = 0;
	for (int i = 0; i < N; i++){
		c[i] = 0;
		for (int j = 0; j < N; j++)
			vis[i][j] = 0;
	}
	search(0);
}