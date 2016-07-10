#include <iostream>
#include <iomanip>
using namespace std;
#define N 200

int main(){
	int ba[N], a[N][N], n, m;
	while (cin >> n >> m, n){
	for (int i = 0; i < N; i++){
		ba[i] = 0;
		for (int j = 0; j < N; j++)
			a[i][j] = 0;
	}
	int x, y, ns = 0;
	for (int i = 0; i < m;i++){
		cin >> x >> y;
		if (a[x][y]==0){
			a[x][y]++;
			ba[y]++;
		}
	}
	for (int k = 0; k < n; k++){
		int s = 1;
		while (s <= n&&ba[s] != 0)s++;
		if (s == n+1)break;
		ba[s] = -1;
		cout << s;
		if (k<n-1)printf(" ");
		for (int t = 0; t <= n; ++t){ if (a[s][t])ba[t]--; }
	}
	cout << endl;
	}
}