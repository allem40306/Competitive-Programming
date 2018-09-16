#include <iostream>
using namespace std;
const int N = 1005;

int main() {
	int m, n, k;
	static int sum[3][N][N] = {};
	string s;
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++) {
			// cout << i << ' ' << j << '\n';
			if (s[j-1] == 'J') {
				sum[0][i][j] = 1;
			} else if (s[j-1] == 'O') {
				sum[1][i][j] = 1;
			} else {
				sum[2][i][j] = 1;
			}
			for (int jj = 0; jj < 3; jj++) {
				sum[jj][i][j] += sum[jj][i - 1][j] + sum[jj][i][j - 1] - sum[jj][i - 1][j - 1];
			}
		}
	}
	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = 0; j < 3; j++) {
			if (j)cout << ' ';
			cout << sum[j][x2][y2] - sum[j][x1 - 1][y2] - sum[j][x2][y1 - 1] + sum[j][x1 - 1][y1 - 1];
		}
		cout << '\n';
	}
}
