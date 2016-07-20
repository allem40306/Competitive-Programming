#include <iostream>
using namespace std;
#define N 3000
short a[N][N], b[N][N], c, n;

int sum(int x, int y){
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[x][i] * b[i][y];
	return sum;
}

int main(){
	while (cin >> n){
		bool flag = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> b[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++){
			cin >> c;
			if (flag){ if (sum(i, j) % 2 != c)flag = 0; }
			}
		printf(flag ? "YES\n" : "NO\n");
	}
}