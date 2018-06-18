#include <iostream>
#include <algorithm>
using namespace std;
#define S 105
int main() {
	int n1, n2, cas = 0, ch1[S], ch2[S];
	while (cin >> n1 >> n2, n1) {
		for (int i = 0; i < n1; i++)cin >> ch1[i];
		for (int j = 0; j < n2; j++)cin >> ch2[j];
		int lcs[S][S] = {};
		for (int a = 1; a <= n1; a++)
			for (int b = 1; b <= n2; b++) {
			if (ch1[a - 1] == ch2[b - 1])
				lcs[a][b] = lcs[a - 1][b - 1] + 1;
			else
				lcs[a][b] = max(lcs[a - 1][b], lcs[a][b - 1]);
			}
		printf("Twin Towers #%d\n", ++cas);
		printf("Number of Tiles : %d\n\n", lcs[n1][n2]);
	}
}