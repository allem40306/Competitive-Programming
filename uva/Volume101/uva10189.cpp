#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define N 105
int dx[9] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[9] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
	int n, m, p = 1;
	while (cin >> n >> m, n){
		string s[N];
		for (int i = 0; i < n; i++)cin >> s[i];
		if (p>1)printf("\n");
		printf("Field #%d:\n", p++);
		for (int j = 0; j < n; j++){
			for (int k = 0; k < m; k++){
				int ans = 0;
				if (s[j][k] == '*')printf("*");
				else {
					for (int a = 0; a < 9; a++){
						int x = j + dx[a], y = k + dy[a];
						if (x < 0 || x >= n || y < 0 || y >= m)continue;
						ans += (s[x][y] == '*');
					}
					printf("%d", ans);
				}
			}
			printf("\n");
		}
	}
}