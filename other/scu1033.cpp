#include <iostream>
#include <iomanip>
using namespace std;
#define N 100
int vis[N][N], c[N], n;
int a[N][N], maxx;

void search(int cur){
	if (cur == n){
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans+=a[i][c[i]];
		maxx = (maxx>ans ? maxx : ans);
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
	n = 8;
	for (int i = 0; i < N; i++){
		c[i] = 0;
		for (int j = 0; j < N; j++)
			vis[i][j] = 0;
	}
	int t;
	while (cin >> t){	
		maxx = 0;
		for (int i = 0; i < t; i++){
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					cin >> a[j][k];
			search(0);
			printf("%5.d\n", maxx);
			maxx = 0;
		}		
	}
}