#include <iostream>
#include <cstring>
using namespace std;
#define N 102
int main() {
	int n;
	while (cin >> n, n) {
		int a[N][N];
		memset(a, 0, sizeof(a));
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++) {
				cin >> a[i][j];
				a[i][n] += a[i][j];
				a[n][j] += a[i][j];
			}
		int ei = 0, ej = 0;
		for (int i = 0;i < n;i++) {
			if (a[i][n] % 2)ei = (ei ? -1 : i);
			if (a[n][i] % 2)ej = (ej ? -1 : i);
		}
		if (ei == 0 && ej == 0)printf("OK\n");
		else if (ei == -1 || ej == -1)printf("Corrupt\n");
		else printf("Change bit (%d,%d)\n", ei+1, ej+1);
	}
}