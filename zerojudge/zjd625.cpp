#include <iostream>
#include <string>
using namespace std;
#define N 150
#define M 8
int dx[M] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[M] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
	string s[N];
	int n, a[N][N], i, j;
	while (cin >> n){
		for (i = 0; i < n; i++)cin >> s[i];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				a[i][j] = 0;
		for (i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (s[i][j] == '*'){
					for (int k = 0; k < M; k++){
						int x = i + dx[k], y = j + dy[k];
						if (x >= 0 && x < n&&y >= 0 && y < n)a[x][y]++;
					}
				}
			}
		}
		for (i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (s[i][j] == '*')printf("*");
				else if (a[i][j])printf("%d", a[i][j]);
				else printf("-");
			}
			printf("\n");
		}
	}
}