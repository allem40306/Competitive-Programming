#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
#define N 200
int n, m, a[N][N];

bool search(int x, int y) {
	int l = a[0][x], r = a[0][y];
	for (int i = 0; i < n; i++) {
		if (a[i][x]>r || a[i][y] < l)return 0;
		if (a[i][x] > l)l = a[i][x];
		if (a[i][y] > r)r = a[i][y];
	}
	return 1;
}

bool solve() {
	for (int i = 0; i < m; i++)
		if (!search(2 * i, 2 * i + 1))return 0;
	return 1;
}

int main() {
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 2 * m; j++)
				cin >> a[i][j];
		printf(solve() ? "Yes\n" : "No\n");
	}
}