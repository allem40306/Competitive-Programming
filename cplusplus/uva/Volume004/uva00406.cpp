#include <iostream>
using namespace std;
#define N 1010
int ox[N], p[N], pr;

void PrimeTable() {
	ox[0] = 0;
	ox[1] = 1;
	pr = 0;
	p[pr++] = 1;
	for (int i = 2; i < N; i++) {
		if (!ox[i]) p[pr++] = i;
		for (int j = 0;i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
	ox[1] = 0;
}

int main() {
	PrimeTable();
	int n, c, t = 0;
	while (cin >> n >> c) {
		printf("%d %d:", n, c);
		int i;
		for (i = 0;p[i] <= n;i++);
		int mid = i / 2 + (i % 2);
		int c1 = c * 2 - (i % 2);
		if (i <= c1) {
			int j = 0;
			while (p[j] <= n)printf(" %d", p[j++]);
		}
		else {
			for (int j = mid - c;c1--;j++)
					printf(" %d", p[j]);
		}
		cout << endl << endl;
	}
}