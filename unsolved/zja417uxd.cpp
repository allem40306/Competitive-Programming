#include <iostream>
using namespace std;
#define N 15
int a[N][N];

int main() {
	int t, n, m, i = 0;
	for (cin >> t; i < t; i++){
		cin >> n >> m;
		for (int i = 0, nn = 1; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = nn, nn++;
		if (m % 2){
			for (int i = 0; i < n; i++){
				for (int j = n - 1; j >= 0; j--)
				printf("%5d", a[j][i]);
				printf("\n");
				}

		}
		else{
			for (int i = n - 1; i >= 0; i--){
				for (int j = n - 1; j >= 0; j--)
				printf("%5d", a[j][i]);
				printf("\n");
				}
		}
	}
}