#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#define N 100
bool vis[N][N], c[N][N];
int n, to;
void search(int cur){
	if (cur == n){
		to++;
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				if (c[i][j])printf("Q");
				else printf("x");
			}
			printf("\n");
		}
		printf("\n");
		return;
	}
	else for (int i = 0; i < n; i++) {
		if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]){
			c[cur][i] = 1;
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
			search(cur + 1);
			c[cur][i] = 0;
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
		}
	}
	return;
}

int main(){
	int ti = 0;
	while (scanf("%d", &n), n){
		to = 0;
		memset(c, 0, sizeof(c));
		memset(vis, 0, sizeof(vis));
		if (ti++)printf("\n");
		search(0);
		printf("%d\n", to);
	}
}
