#include <iostream>
using namespace std;
#define N 20000000
int ox[N], p[N], pr;

void PrimeTable() {
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i*i < N; i++) {
		if (!ox[i]) p[pr++] = i;
		for (int j = 0;i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}

int main() {
	PrimeTable();
	int n;
	while (cin >> n) {
		int sum = 0;
		for (int i = 0;p[i] && p[i] <= n;i++) {
			while (n%p[i] == 0) {
				sum += p[i];
				n /= p[i];
				if (n == 1)break;
			}
		}
		cout << sum << endl;
	}
}