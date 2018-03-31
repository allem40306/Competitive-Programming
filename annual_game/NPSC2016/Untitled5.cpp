#include <stdio.h>

int main() {
	int N, M, i, j, k, min, n[105][105] = {};
	for (i = 1; i <= 100; i++)
		n[i][1] = n[1][i] = i, n[i][i] = 1;
	for (i = 1; i <= 100; i++)
		for (j = 1; j <= 100; i != 1 && j != 1 && i != j && (n[i][j] = min), j++) {
			for (min = 1000000, k = 1; k < j; k++)
				min > n[i][k]+n[i][j-k] && (min = n[i][k]+n[i][j-k]);
			for (k = 1; k < i; k++)
				min > n[k][j]+n[i-k][j] && (min = n[k][j]+n[i-k][j]);
		}
	scanf("%d%d", &N, &M), printf("%d\n", n[N][M]);
}
